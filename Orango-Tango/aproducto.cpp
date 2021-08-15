#include "aproducto.h"
#include "ui_aproducto.h"
#include "cbasedatos.h"
#include <QMessageBox>
#include "inempleados.h"

AProducto::AProducto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AProducto)
{
    ui->setupUi(this);
}

AProducto::~AProducto()
{
    delete ui;
}

void AProducto::on_pushButton_2_clicked()
{
    QString Errores="";
    bool Error=0;
    QRegExp* patron=new QRegExp("^[A-Z][(a-z|0-9|A-Z)]+(\\s[A-Z][(a-z|0-9|A-Z)]+)?$");
    QString nombre = ui->nombre->text();
    if(not(patron->exactMatch(nombre)==true)){
        Error=1;
        Errores+="Nombre\n";
    }

    patron = new QRegExp("^[0-9]{2,10}$");
    QString codigo = ui->codigo->text();
    if(not(patron->exactMatch(codigo)==true)){
        Error=1;
        Errores+="Codigo\n";
    }
    QString Dimension = ui->dimension->text();
    QString color = ui->color->text();

    patron = new QRegExp("^[1-9][0-9]{0,100}$");
    QString precio = ui->precio->text();
    if(not(patron->exactMatch(precio)==true)){
        Error=1;
        Errores+="Precio\n";
    }
    QString descipcion = ui->descripcion->text();

    patron = new QRegExp("^[1-9][0-9]{0,100}$");
    QString costo = ui->costo->text();
    if(not(patron->exactMatch(costo)==true)){
        Error=1;
        Errores+="Costo\n";
    }

    patron = new QRegExp("^[0-9]{1,100}$");
    QString cantidad = ui->cantidad->text();
    if(not(patron->exactMatch(cantidad)==true)){
        Error=1;
        Errores+="Cantidad\n";
    }
    if(Error){
        QMessageBox msg;
        msg.setText("los errores son:\n"+Errores);
        msg.exec();
    }else{
        QMessageBox msg;
        CBaseDatos Base;
        Base.ActualizarInventario(nombre,codigo,descipcion,Dimension,color,precio,costo,cantidad);
        ui->pushButton_2->setDisabled(1);
        msg.setText("Registro completado");
        msg.exec();
        inEmpleados *inte=new inEmpleados;
        inte->show();
        this->close();
    }
}
