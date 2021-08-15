#include "aempleado.h"
#include "ui_aempleado.h"
#include "registro.h"
#include "cusuario.h"
#include <QMessageBox>
#include <cbasedatos.h>
AEmpleado::AEmpleado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AEmpleado)
{
    ui->setupUi(this);
}

AEmpleado::~AEmpleado()
{
    delete ui;
}

void AEmpleado::on_pushButton_clicked()
{
    QString Errores="";
    bool Error=0;
    QRegExp* patron=new QRegExp("^[A-Z][(a-z|0-9|A-Z)]+(\\s[A-Z][(a-z|0-9|A-Z)]+)?$");
    patron = new QRegExp("^[(a-z|0-9|A-Z)]{6,30}$");
    QString usuario = ui->usuario->text();
    if(not(patron->exactMatch(usuario)==true)){
        Error=1;
        Errores+="Usuario\n";
    }

    patron = new QRegExp("^[(a-z{1}|0-9{1}|A-Z{1})]{8,20}$");
    QString cont = ui->cont->text();
    if(not(patron->exactMatch(cont)==true)){
        Error=1;
        Errores+="Contraseña\n";
    }
    if(Error){
        QMessageBox msg;
        msg.setText("los errores son:\n"+Errores);
        msg.exec();
    }else{
        QMessageBox msg;
        CBaseDatos Base;
        if(Base.VerificarEmpleados(usuario,cont)){
            msg.setText("Nombre de Usuario ya existente");
            msg.exec();
        }else{
            CBaseDatos Base2;
            Base2.ActualizarEpleadosLogin(usuario,cont);
            ui->pushButton->setDisabled(1);
            msg.setText("Registro completado");
            msg.exec();
            Registro *reg=new Registro;
            reg->show();
            this->close();
        }

    }
}
