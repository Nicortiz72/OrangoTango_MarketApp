#include "cregistro.h"

CRegistro::CRegistro(){
    RegTmp = new QFile("RegistroTmp.txt");
    Reg = new QFile("Reg.txt");
}
bool CRegistro::verificar(QString codigo, QString cant){
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    QString lin;
    QStringList lines;
    while(!RegTmp->atEnd()){
        lin=RegTmp->readLine();
        lines=lin.split(":");
        if(codigo==lines[0]){
            cant+=lines[1].toInt();
        }
    }
    RegTmp->close();
    CBaseDatos BD;
    QVector <CProductos> tienda = BD.getInventario();
    int i;
    for(i=0;i<tienda.length();i++){
        if(codigo==tienda[i].getCodigo()){
            if(cant<=tienda[i].getCantidad()){
                return 1;
            }
        }
    }
    RegTmp->close();
    return 0;
}
CProductos CRegistro::Buscar(QString codigo, QString cant){
    CBaseDatos BD;
    QVector <CProductos> tienda = BD.getInventario();
    CProductos nul;
    int i;
    QStringList lines;
    for(i=0;i<tienda.length();i++){
        if(codigo==tienda[i].getCodigo()){
            tienda[i].setCantidad(cant);
            return tienda[i];
        }
    }
    return nul;
}
void CRegistro::setCliente(QString usuario){
    RegTmp->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(RegTmp);
    out << usuario<<":\n";
    RegTmp->close();
}
void CRegistro::setCarrito(CCarrito car){
    QVector <CProductos> productos=car.getProductos();
    int i;
    QString line="";
    for(i=0;i<productos.length();i++){
        line.append(productos[i].getCodigo()+":"+QString::number(productos[i].getCantidad())+":\n");
    }
    RegTmp->open(QIODevice::ReadWrite | QIODevice::Text);
    RegTmp->readLine();
    QTextStream out(RegTmp);
    out <<line;
    RegTmp->close();
}
void CRegistro::AgregarCarrito(CProductos pro){
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,codigo,cantidad;
    QString lin,line=RegTmp->readLine();
    QStringList  nombre=line.split(":");
    line=nombre[0];
    while(!RegTmp->atEnd()){
        lin=RegTmp->readLine();
        lines=lin.split(":");
        codigo.append(lines[0]);
        cantidad.append(lines[1]);
    }
    RegTmp->close();
    RegTmp->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(RegTmp);
    int i;
    bool pasa=1;
    out<<line<<":\n";
    for(i=0;i<codigo.length();i++){
        if(pro.getCodigo()==codigo[i]){
            out<<codigo[i]<<":"<<QString::number((cantidad[i].toInt())+pro.getCantidad())<<":\n";
            pasa=0;
        }else{
            out<<codigo[i]<<":"<<cantidad[i]<<":\n";
        }
    }
    if(pasa)out<<pro.getCodigo()<<":"<<pro.getCantidad()<<":\n";
    RegTmp->close();
}
CCarrito CRegistro::getCarrito(){
    QVector <CProductos> productos;
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    RegTmp->readLine();
    QStringList lineas;
    QString linea;
    while(!RegTmp->atEnd()){
        linea=RegTmp->readLine();
        lineas=linea.split(":");
        productos.append(this->Buscar(lineas[0],lineas[1]));
    }
    CCarrito car;
    car.setCarrito(productos);
    RegTmp->close();
    return car;
}
QVector <CProductos> CRegistro::getProductos(){
    QVector <CProductos> productos;
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    RegTmp->readLine();
    QStringList lineas;
    QString linea;
    while(!RegTmp->atEnd()){
        linea=RegTmp->readLine();
        lineas=linea.split(":");
        productos.append(this->Buscar(lineas[0],lineas[1]));
    }
    RegTmp->close();
    return productos;
}
QString CRegistro::getCliente(){
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lineas;
    QString linea;
    linea=RegTmp->readLine();
    lineas=linea.split(":");
    RegTmp->close();
    return lineas[0];
}
void CRegistro::EliminarCarrito(CProductos pro){
    CCarrito car = this->getCarrito();
    car.EliminarProducto(pro);
    this->setCarrito(car);
}
void CRegistro::Quitar(CProductos pro){
    RegTmp->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,codigo,cantidad;
    QString lin,line=RegTmp->readLine();
    QStringList  nombre=line.split(":");
    line=nombre[0];
    while(!RegTmp->atEnd()){
        lin=RegTmp->readLine();
        lines=lin.split(":");
        codigo.append(lines[0]);
        cantidad.append(lines[1]);
    }
    RegTmp->close();
    RegTmp->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(RegTmp);
    int i;
    out<<line<<":\n";
    for(i=0;i<codigo.length();i++){
        if(pro.getCodigo()==codigo[i]){
            if((cantidad[i].toInt())>0)
                out<<codigo[i]<<":"<<QString::number((cantidad[i].toInt())-1)<<":\n";
        }else{
            out<<codigo[i]<<":"<<cantidad[i]<<":\n";
        }
    }
    RegTmp->close();
}

QString CRegistro::getNfactura(){
    Reg->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lineas;
    QString linea;
    linea=Reg->readLine();
    lineas=linea.split(":");
    Reg->close();
    return lineas[0];
}
QString CRegistro::getVentas(CProductos pro){
    Reg->open(QIODevice::ReadOnly | QIODevice::Text);
    Reg->readLine();
    QStringList lineas;
    QString linea,ven="";
    while(!Reg->atEnd()){
        linea=Reg->readLine();
        lineas=linea.split(":");
        if(pro.getCodigo()==lineas[0]){
            ven=lineas[1];
        }
    }
    Reg->close();
    return ven;
}
void CRegistro::setVentas(CProductos pro){
    Reg->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,codigo,cantidad;
    QString lin,line=Reg->readLine();
    QStringList  nombre=line.split(":");
    line=nombre[0];
    if(!Reg->atEnd()){
        while(!Reg->atEnd()){
            lin=Reg->readLine();
            lines=lin.split(":");
            codigo.append(lines[0]);
            cantidad.append(lines[1]);
        }
        Reg->close();
        Reg->open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(Reg);
        int i;
        bool pasa=1;
        out<<line<<":\n";
        for(i=0;i<codigo.length();i++){
            if(pro.getCodigo()==codigo[i]){
                out<<codigo[i]<<":"<<QString::number((cantidad[i].toInt())+pro.getCantidad())<<":\n";
                pasa=0;
            }else{
                out<<codigo[i]<<":"<<cantidad[i]<<":\n";
            }
        }
        if(pasa)out<<pro.getCodigo()<<":"<<QString::number(pro.getCantidad())<<":\n";
        Reg->close();
    }else{
        Reg->close();
        Reg->open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(Reg);
        out<<line<<":\n";
        out<<pro.getCodigo()<<":"<<pro.getCantidad()<<":\n";
        Reg->close();
    }
}
void CRegistro::sumaNfactura(){
    Reg->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,codigo,cantidad;
    QString lin,line=Reg->readLine();
    QStringList  nombre=line.split(":");
    line=nombre[0];
    while(!Reg->atEnd()){
        lin=Reg->readLine();
        lines=lin.split(":");
        codigo.append(lines[0]);
        cantidad.append(lines[1]);
    }
    Reg->close();
    Reg->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(Reg);
    int i;
    out<<QString::number(line.toInt()+1)<<":\n";
    for(i=0;i<codigo.length();i++){
        out<<codigo[i]<<":"<<cantidad[i]<<":\n";
    }
    Reg->close();

}

void CRegistro::Facturar(bool des){
    QString nfac=this->getNfactura();
    this->sumaNfactura();
    QFile *fac=new QFile("FacturaN"+nfac+".txt");
    CBaseDatos BD;
    CUsuario user=BD.getCliente(this->getCliente());
    QVector <CProductos> productos = this->getProductos();
    int suma=0;
    int descuento=0;
    fac->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(fac);
    out<<"                    ORANGO TANGO\n\n";
    out<<"                   Factura N"+nfac+"\n\n";
    out<<"Cliente: "<<user.getNombres()<<" "<<user.getApellidos()<<"\n";
    out<<"Documento: "<<user.getID()<<"\n";
    out<<"Celular: "<<user.getCelular()<<"\n";
    out<<"\n///////////////////////////////////////////////////////\n";
    out<<"Compras:\n";
    out<<"Codigo Nombre Cantidad Precio Total\n";
    out<<"-------------------------------------------------------\n";
    for(int i=0;i<productos.length();i++){
        suma+=productos[i].getCantidad()*productos[i].getPrecio();
        out<<productos[i].getCodigo()<<" / "<<productos[i].getNombre()<<" / "<<productos[i].getCantidad()<<" / "<<productos[i].getPrecio()<<" / "<<QString::number(productos[i].getCantidad()*productos[i].getPrecio())<<"\n";
    }
    out<<"-------------------------------------------------------\n";
    if(des)descuento=suma/10;
    out<<"SUBTOTAL:  "<<suma<<" $\n";
    out<<"DESCUENTO:  "<<descuento<<" $\n";
    out<<"TOTAL:  "<<suma-descuento<<" $\n";
    out<<"\n///////////////////////////////////////////////////////\n";
    fac->close();
}


void CRegistro::FacturarProyecto(CProyectos proyecto){
    QString nfac=this->getNfactura();
    this->sumaNfactura();
    QFile *fac=new QFile("FacturaN"+nfac+".txt");
    CBaseDatos BD;
    CUsuario user=BD.getCliente(this->getCliente());
    fac->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(fac);
    out<<"                    ORANGO TANGO\n\n";
    out<<"                   Factura N"+nfac+"\n\n";
    out<<"Cliente: "<<user.getNombres()<<" "<<user.getApellidos()<<"\n";
    out<<"Documento: "<<user.getID()<<"\n";
    out<<"Celular: "<<user.getCelular()<<"\n";
    out<<"\n///////////////////////////////////////////////////////\n";
    out<<"Proyecto:\n";
    out<<"Descripcion\n";
    out<<"-------------------------------------------------------\n";
    out<<proyecto.getDescripcion()<<"\n";
    out<<"-------------------------------------------------------\n";
    out<<"SUBTOTAL:  "<<proyecto.getPrecio()<<" $\n";
    out<<"DESCUENTO:  "<<"0"<<" $\n";
    out<<"TOTAL:  "<<proyecto.getPrecio()<<" $\n";
    out<<"\n///////////////////////////////////////////////////////\n";
    fac->close();
}
