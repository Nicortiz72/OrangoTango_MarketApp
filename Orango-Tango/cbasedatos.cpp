#include "cbasedatos.h"
#include <QMessageBox>
CBaseDatos::CBaseDatos(){
    user=new QFile("user.txt");
    Clientes=new QFile("Clientes.txt");
    Proyectos=new QFile("Proyectos.txt");
    Inventario=new QFile("Inventario.txt");
    Empleados=new QFile("Empleados.txt");
    preguntas = new QFile("Preguntas.txt");
}
QString CBaseDatos::InCrip(QString lineA){
    int i;
    QByteArray line=lineA.toLocal8Bit();
    for (i=0;i<line.length();i++)line[i]=(((line[i]-97)+3)%27)+97;
    QString lineB(line);
    return lineB;
}
QString CBaseDatos::DeCrip(QString lineA){
    QByteArray line=lineA.toLocal8Bit();
    int i;
    for (i=0;i<line.length();i++)line[i]=(((line[i]-97)-3)%27)+97;
    QString lineB(line);
    return lineB;
}
void CBaseDatos::ActualizarUser(QString nombre,QString cont){
    user->open(QIODevice::Append | QIODevice::Text);
    cont=this->InCrip(cont);
    QString line=nombre+":"+cont+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(user);
    out << line;
    user->close();
}
bool CBaseDatos::VerificarUser(QString nombre,QString cont){
    QString line;
    QStringList lines;
    user->open(QIODevice::ReadOnly | QIODevice::Text);
    cont=this->InCrip(cont);
    while (!user->atEnd()) {
        line = user->readLine();
        lines=line.split(':');
        if(lines[0]==nombre and lines[1]==cont)return 1;
    }
    user->close();
    return 0;
}
void CBaseDatos::ActualizarClientes(QString Nom, QString Ap, QString FN, bool Gen, QString EC, QString ID, QString TCred, QString Direc, QString Tel, QString Cel, QString Correo, QString Us, QString Pass, QString PSecret){
    Clientes->open(QIODevice::Append | QIODevice::Text);
    QString sex="0";
    if(Gen){
        sex="1";
    }
    Pass=this->InCrip(Pass);
    QString line=Us+":"+Ap+":"+FN+":"+sex+":"+EC+":"+ID+":"+TCred+":"+Direc+":"+Tel+":"+Cel+":"+Correo+":"+Nom+":"+Pass+":"+PSecret+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(Clientes);
    out << lineA;
    Clientes->close();
}
CUsuario CBaseDatos::getCliente(QString usuario){
    QString line;
    QStringList lines;
    Clientes->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!Clientes->atEnd()) {
        line = Clientes->readLine();
        lines=line.split(':');
        if(lines[0]==usuario)break;
    }
    bool sex=1;
    if(lines[3]=="0"){
        sex=0;
    }
    QString lineA[14];
    int i;
    for (i=0;i<14;i++)lineA[i]=lines[i];
    lineA[12]=this->DeCrip(lineA[12]);
    CUsuario cliente(lineA[11],lineA[1],lineA[2],sex,lineA[4],lineA[5],lineA[6],lineA[7],lineA[8],lineA[9],lineA[10],lineA[0],lineA[12],lineA[13]);
    Clientes->close();
    return cliente;

}
QVector <CUsuario> CBaseDatos::getClientes(){
    QString line;
    QStringList lines;
    QVector <CUsuario> usuariosL;
    CUsuario* utmp=new CUsuario;
    bool sex=1;
    int i;
    QString lineA[14];
    Clientes->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!Clientes->atEnd()) {
        line = Clientes->readLine();
        lines=line.split(':');
        if(lines[3]=="0"){
            sex=0;
        }
        for (i=0;i<14;i++)lineA[i]=lines[i];
        utmp=new CUsuario(lineA[11],lineA[1],lineA[2],sex,lineA[4],lineA[5],lineA[6],lineA[7],lineA[8],lineA[9],lineA[10],lineA[0],lineA[12],lineA[13]);
        usuariosL.append(*utmp);
    }
    Clientes->close();
    return usuariosL;

}
void CBaseDatos::ActualizarInventario(QString Nom,QString Cod,QString Dir,QString Dim,QString Col,QString Pre,QString Cos,QString Can){
    Inventario->open(QIODevice::Append | QIODevice::Text);
    QString line=Nom+":"+Cod+":"+Dir+":"+Dim+":"+Col+":"+Pre+":"+Cos+":"+Can+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(Inventario);
    out << lineA;
    Inventario->close();
}
QVector<CProductos> CBaseDatos::getInventario(){
    QVector<CProductos> productos;
    CProductos* protmp=new CProductos;
    QString line;
    QStringList lines;
    Inventario->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!Inventario->atEnd()) {
        line = Inventario->readLine();
        lines=line.split(':');
        QString lineA[8];
        int i;
        for (i=0;i<8;i++)lineA[i]=lines[i];
        protmp= new CProductos(lineA[0],lineA[1],lineA[2],lineA[3],lineA[4],(lineA[5]),(lineA[6]),(lineA[7]));
        productos.append(*protmp);
    }
    Inventario->close();
    return productos;

}
void CBaseDatos::ActualizarProyectos(QString name,QString Des,QString Cos,QString Pre){
    Proyectos->open(QIODevice::Append | QIODevice::Text);
    QString line=name+":"+Des+":"+Cos+":"+Pre+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(Proyectos);
    out << lineA;
    Proyectos->close();
}
void CBaseDatos::setProyectos(QString Des,QString cos, QString pre){
    Proyectos->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,nombre,desc,cost,prec;
    QString lin;
    while(!Proyectos->atEnd()){
        lin=Proyectos->readLine();
        lines=lin.split(":");
        nombre.append(lines[0]);
        desc.append(lines[1]);
        cost.append(lines[2]);
        prec.append(lines[3]);
    }
    Proyectos->close();
    Proyectos->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(Proyectos);
    int i;
    for(i=0;i<nombre.length();i++){
        if(desc[i]==Des){
            out<<nombre[i]<<":"<<desc[i]<<":"<<cos<<":"<<pre<<":\n";
        }else{
            out<<nombre[i]<<":"<<desc[i]<<":"<<cost[i]<<":"<<prec[i]<<":\n";
        }
    }
    Proyectos->close();

}
QVector<CProyectos> CBaseDatos::getProyectos(){
    QVector<CProyectos> Tproyectos;
    CProyectos* protmp;
    QString line;
    QStringList lines;
    Proyectos->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!Proyectos->atEnd()) {
        line = Proyectos->readLine();
        lines=line.split(':');
        QString lineA[4];
        int i;
        for (i=0;i<4;i++)lineA[i]=lines[i];
        protmp=new CProyectos(lineA[0],lineA[1],lineA[2],lines[3]);
        Tproyectos.append(*protmp);
    }
    Proyectos->close();
    return Tproyectos;
}
void CBaseDatos::setInventario(QVector<CProductos> productos){
    int i;
    Inventario->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(Inventario);
    QString line;
    for(i=0;i<productos.length();i++){
        line=productos[i].getNombre()+":"+productos[i].getCodigo()+":"+productos[i].getDescripcion()+":"+productos[i].getDimension()+":"+productos[i].getColor()+":"+QString::number(productos[i].getPrecio())+":"+QString::number(productos[i].getCosto())+":"+QString::number(productos[i].getCantidad())+":"+"\n";
        out << line;
    }
    Inventario->close();
}
void CBaseDatos::ActualizarEpleadosLogin(QString nombre,QString cont){
    Empleados->open(QIODevice::Append | QIODevice::Text);
    cont=this->InCrip(cont);
    QString line=nombre+":"+cont+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(Empleados);
    out << line;
    Empleados->close();
}
bool CBaseDatos::VerificarEmpleados(QString nombre,QString cont){
    QString line;
    QStringList lines;
    Empleados->open(QIODevice::ReadOnly | QIODevice::Text);
    cont=this->InCrip(cont);
    while (!Empleados->atEnd()) {
        line = Empleados->readLine();
        lines=line.split(':');
        if(lines[0]==nombre and lines[1]==cont)return 1;
    }
    Empleados->close();
    return 0;
}
QVector <CUsuario> CBaseDatos::getEmpleados(){
    QString line;
    QStringList lines;
    QVector <CUsuario> empleado;
    Empleados->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!Empleados->atEnd()) {
        line = Empleados->readLine();
        lines=line.split(':');
        empleado.append(this->getCliente(lines[0]));
    }
    Empleados->close();
    return empleado;
}
void CBaseDatos::setPregunta(CPregunta pre){
    preguntas->open(QIODevice::Append | QIODevice::Text);
    QString line=pre.getPregunta()+":"+pre.getRespuesta()+":"+"\n";
    QByteArray lineA=line.toLocal8Bit();
    QTextStream out(preguntas);
    out << lineA;
    preguntas->close();
}
QVector <CPregunta> CBaseDatos::getPreguntas(){
    QString line;
    QStringList lines;
    QVector <CPregunta> pregunta;
    CPregunta *tmp;
    preguntas->open(QIODevice::ReadOnly | QIODevice::Text);
    while (!preguntas->atEnd()) {
        line = preguntas->readLine();
        lines=line.split(':');
        tmp=new CPregunta(lines[0],lines[1]);
        pregunta.append(*tmp);
    }
    preguntas->close();
    return pregunta;
}
void CBaseDatos::recreatePreguntas(QString pre, QString res){
    preguntas->open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList lines,pregunta,respuesta;
    QString lin;
    while(!preguntas->atEnd()){
        lin=preguntas->readLine();
        lines=lin.split(":");
        pregunta.append(lines[0]);
        respuesta.append(lines[1]);
    }
    preguntas->close();
    preguntas->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(preguntas);
    int i;
    for(i=0;i<pregunta.length();i++){
        if(pregunta[i]==pre){
            out<<pregunta[i]<<":"<<res<<":\n";
        }else{
            out<<pregunta[i]<<":"<<respuesta[i]<<":\n";
        }
    }
    preguntas->close();
}

