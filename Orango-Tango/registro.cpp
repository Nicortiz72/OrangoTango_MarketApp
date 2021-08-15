#include "registro.h"
#include "ui_registro.h"
#include "cusuario.h"
#include <QMessageBox>
#include <cbasedatos.h>
Registro::Registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_pushButton_clicked()
{
    bool Error=0, Gen;
    QString Errores="";
    QRegExp* patron=new QRegExp("^[A-Z][(a-z|0-9|A-Z)]+(\\s[A-Z][(a-z|0-9|A-Z)]+)?$");
    QString Nombres = ui->Nombres->text();
    if(not(patron->exactMatch(Nombres)==true)){
        Error=1;
        Errores+="Nombre\n";
    }

    patron = new QRegExp("^[A-Z][(a-z|0-9|A-Z)]+(\\s[A-Z][(a-z|0-9|A-Z)]+)?$");
    QString Apellidos = ui->Apellidos->text();
    if(not(patron->exactMatch(Apellidos)==true)){
        Error=1;
        Errores+="Apellidos\n";
    }

    if(ui->Hombre->isChecked())
        Gen = 1;
    else
        Gen = 0;

    patron = new QRegExp("^[(a-z|A-Z)]{4,30}$");
    QString EstCivil = ui->EstCivil->text();
    if(not(patron->exactMatch(EstCivil)==true)){
        Error=1;
        Errores+="Estado Civil\n";
    }

    patron = new QRegExp("^[1-9][0-9]{1,30}$");
    QString Cedula = ui->ID->text();
    if(not(patron->exactMatch(Cedula)==true)){
        Error=1;
        Errores+="Cedula\n";
    }
    patron = new QRegExp("^[0-3][0-9]/[0-1][0-9]/[0-9]{4}$");
    QString Fecha = ui->FN->text();
    if(not(patron->exactMatch(Fecha)==true)){
        Error=1;
        Errores+="Fecha\n";
    }
    patron = new QRegExp("^[0-9]{16}$");
    QString TCredito = ui->TCredito->text();
    if(not(patron->exactMatch(TCredito)==true) and TCredito!=""){
        Error=1;
        Errores+="Tarjeta de credito\n";
    }
    QString Direccion = ui->Direccion->text();
    patron = new QRegExp("^[1-9][0-9]{6}$");
    QString tel = ui->Tel->text();
    if(not(patron->exactMatch(tel)==true)){
        Error=1;
        Errores+="Telefono\n";
    }

    patron = new QRegExp("^3[0-9]{9}$");
    QString celular = ui->Cel->text();
    if(not(patron->exactMatch(celular)==true)){
        Error=1;
        Errores+="Celular\n";
    }

    patron = new QRegExp("^[(a-z|0-9|A-Z)]{1,30}@[(a-z|0-9|A-Z)]+(.)[(a-z|0-9|A-Z)]{2,10}$");
    QString correo = ui->Correo->text();
    if(not(patron->exactMatch(correo)==true)){
        Error=1;
        Errores+="Correo\n";
    }

    patron = new QRegExp("^[(a-z|0-9|A-Z)]{6,30}$");
    QString usuario = ui->Usuario->text();
    if(not(patron->exactMatch(usuario)==true)){
        Error=1;
        Errores+="Usuario\n";
    }

    patron = new QRegExp("^[(a-z{1}|0-9{1}|A-Z{1})]{8,20}$");
    QString cont = ui->Cont->text();
    if(not(patron->exactMatch(cont)==true)){
        Error=1;
        Errores+="Contraseña\n";
    }

    patron = new QRegExp("^[(a-z|0-9|A-Z)]{2,20}$");
    QString palabra = ui->PSecreta->text();
    if(not(patron->exactMatch(palabra)==true)){
        Error=1;
        Errores+="Palabra\n";
    }
    if(Error){
        QMessageBox msg;
        msg.setText("los errores son:\n"+Errores);
        msg.exec();
    }else{
        QMessageBox msg;
        CUsuario usu(Nombres, Apellidos,Fecha,Gen,EstCivil,Cedula,TCredito,Direccion,tel,celular,correo,usuario,cont,palabra);
        CBaseDatos Base;
        if(Base.VerificarUser(usuario,cont)){
            msg.setText("Nombre de Usuario ya existente");
            msg.exec();
        }else{
            CBaseDatos Base2;
            Base2.ActualizarUser(usuario,cont);
            Base.ActualizarClientes(Nombres, Apellidos,Fecha,Gen,EstCivil,Cedula,TCredito,Direccion,tel,celular,correo,usuario,cont,palabra);
            ui->pushButton->setDisabled(1);
            msg.setText("Registro completado");
            msg.exec();
            this->close();
        }

    }
}
