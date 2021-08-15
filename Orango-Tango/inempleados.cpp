#include "inempleados.h"
#include "ui_inempleados.h"
#include <cregistro.h>
#include <mainwindow.h>
#include <QMessageBox>
#include <aempleado.h>
#include <aproducto.h>
#include <apregunta.h>

inEmpleados::inEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inEmpleados)
{
    ui->setupUi(this);
    CRegistro reg;
    if(reg.getCliente()=="admin"){
        ui->empleados->setDisabled(0);
        ui->aempleado->setDisabled(0);
    }
    ui->nombre->setText(reg.getCliente());
    CBaseDatos BD;
    QVector <CProductos> productos = BD.getInventario();
    ui->tableWidget->setRowCount(productos.length());
    ui->tableWidget->setColumnCount(9);
    for(int i=0; i<productos.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(productos[i].getCodigo()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(productos[i].getNombre()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(productos[i].getDescripcion()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(productos[i].getDimension()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(productos[i].getColor()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(QString::number(productos[i].getPrecio())+" $"));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(QString::number(productos[i].getCantidad())));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(QString::number(productos[i].getCosto())));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(reg.getVentas(productos[i])));
    }
    ui->tableWidget->sortItems(8,Qt::DescendingOrder);
}

inEmpleados::~inEmpleados()
{
    delete ui;
}

void inEmpleados::on_Productos_clicked()
{
    ui->tableWidget->clear();
    QStringList headlines;
    headlines<<"Codigo"<<"Nombre"<<"Descripcion"<<"Dimension"<<"Color"<<"Precio"<<"Cantidad"<<"Costo"<<"No.Ventas";
    CBaseDatos BD;
    CRegistro reg;
    QVector <CProductos> productos = BD.getInventario();
    ui->tableWidget->setRowCount(productos.length());
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(headlines);
    for(int i=0; i<productos.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(productos[i].getCodigo()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(productos[i].getNombre()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(productos[i].getDescripcion()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(productos[i].getDimension()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(productos[i].getColor()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(QString::number(productos[i].getPrecio())+" $"));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(QString::number(productos[i].getCantidad())));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(QString::number(productos[i].getCosto())));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(reg.getVentas(productos[i])));
    }
    ui->tableWidget->sortItems(8,Qt::DescendingOrder);
}

void inEmpleados::on_pushButton_clicked()
{
    MainWindow *mainw = new MainWindow;
    mainw->show();
    this->close();
}

void inEmpleados::on_proyectos_clicked()
{
    ui->tableWidget->clear();
    QStringList headlines;
    headlines<<"Usuario"<<"Descripcion"<<"Costo"<<"Precio"<<"";
    CBaseDatos BD;
    QVector <CProyectos> proyectos = BD.getProyectos();
    ui->tableWidget->setRowCount(proyectos.length());
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headlines);
    for(int i=0; i<proyectos.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(proyectos[i].getUsuario()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(proyectos[i].getDescripcion()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(proyectos[i].getCosto()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(proyectos[i].getPrecio()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem("GUARDAR"));
    }

}

void inEmpleados::on_clientes_clicked()
{
    ui->tableWidget->clear();
    QStringList headlines;
    headlines<<"Nombre"<<"Apellido"<<"Usuario"<<"Estado Civil"<<"Telefono"<<"Celular"<<"Fecha Nacimiento"<<"Direccion"<<"T Credito"<<"Documento";
    CBaseDatos BD;
    QVector <CUsuario> clientes = BD.getClientes();
    ui->tableWidget->setRowCount(clientes.length());
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(headlines);
    for(int i=0; i<clientes.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(clientes[i].getNombres()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(clientes[i].getApellidos()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(clientes[i].getUsuario()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(clientes[i].getEstCivil()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(clientes[i].getTel()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(clientes[i].getCelular()));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(clientes[i].getFechaN()));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(clientes[i].getDireccion()));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(clientes[i].getTCredito()));
        ui->tableWidget->setItem(i,9, new QTableWidgetItem(clientes[i].getID()));
    }
}

void inEmpleados::on_empleados_clicked()
{
    ui->tableWidget->clear();
    QStringList headlines;
    headlines<<"Nombre"<<"Apellido"<<"Usuario"<<"Estado Civil"<<"Telefono"<<"Celular"<<"Fecha Nacimiento"<<"Direccion"<<"T Credito"<<"Documento";
    CBaseDatos BD;
    QVector <CUsuario> empleados = BD.getEmpleados();
    ui->tableWidget->setRowCount(empleados.length());
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(headlines);
    for(int i=0; i<empleados.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(empleados[i].getNombres()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(empleados[i].getApellidos()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(empleados[i].getUsuario()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(empleados[i].getEstCivil()));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(empleados[i].getTel()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(empleados[i].getCelular()));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(empleados[i].getFechaN()));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(empleados[i].getDireccion()));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(empleados[i].getTCredito()));
        ui->tableWidget->setItem(i,9, new QTableWidgetItem(empleados[i].getID()));
    }
}

void inEmpleados::on_aempleado_clicked()
{
    AEmpleado *in = new AEmpleado;
    in->show();
}

void inEmpleados::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int n=item->row();
    QMessageBox msg;
    if(item->text()=="GUARDAR"){
        QString costo=ui->tableWidget->item(n,2)->text();
        QString precio=ui->tableWidget->item(n,3)->text();
        CBaseDatos BD;
        BD.setProyectos(ui->tableWidget->item(n,1)->text(),costo,precio);
        msg.setText("Proyecto actualizado");
        msg.exec();
    }else{
        if(item->text()=="ACTUALIZAR"){
            QString pregunta=ui->tableWidget->item(n,0)->text();
            QString respuesta=ui->tableWidget->item(n,1)->text();
            CBaseDatos BD;
            BD.recreatePreguntas(pregunta,respuesta);
            msg.setText("Pregunta actualizada");
            msg.exec();
        }else{
            if(ui->tableWidget->columnCount()>=5){
                if(item->column()==1 and ui->tableWidget->item(n,4)->text()=="GUARDAR"){
                    msg.setText(item->text());
                    msg.exec();
                }
            }else{
                if(ui->tableWidget->columnCount()>=3){
                    if(ui->tableWidget->item(n,2)->text()=="ACTUALIZAR"){
                        msg.setText(item->text());
                        msg.exec();
                    }
                }
            }
        }
    }
}

void inEmpleados::on_aproducto_clicked()
{
    AProducto *intap=new AProducto;
    intap->show();
}

void inEmpleados::on_clientes_2_clicked()
{
    ui->tableWidget->clear();
    QStringList headlines;
    headlines<<"Pregunta"<<"Respuesta"<<"";
    CBaseDatos BD;
    QVector <CPregunta> preguntas = BD.getPreguntas();
    ui->tableWidget->setRowCount(preguntas.length());
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headlines);
    for(int i=0; i<preguntas.length(); i++){
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(preguntas[i].getPregunta()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(preguntas[i].getRespuesta()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem("ACTUALIZAR"));
    }
}

void inEmpleados::on_pushButton_2_clicked()
{
    apregunta *intp=new apregunta;
    intp->show();
    this->close();
}
