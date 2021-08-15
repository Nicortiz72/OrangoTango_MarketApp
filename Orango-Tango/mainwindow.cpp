#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registro.h"
#include <QString>
#include <cbasedatos.h>
#include <intusuario.h>
#include <QMessageBox>
#include <cregistro.h>
#include "inempleados.h"
#include "intpreguntas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BRegistrar_clicked()
{
    Registro *registro = new Registro;
    registro->show();
}

void MainWindow::on_BIngresar_clicked()
{
    QString Usuario = ui->Usuario->text();
    QString contr = ui->Cont->text();
    CBaseDatos base;
    if(base.VerificarEmpleados(Usuario,contr)){
        CRegistro Reg;
        Reg.setCliente(Usuario);
        inEmpleados *inte = new inEmpleados;
        inte->show();
        this->close();
    }else{
        if(base.VerificarUser(Usuario,contr)){
            CRegistro Reg;
            Reg.setCliente(Usuario);
            Intusuario *intu = new Intusuario;
            intu->show();
            this->close();
        }else{
            QMessageBox msg;
            msg.setText("La contraseña o el usuario no coinciden");
            msg.exec();
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    Intpreguntas *intp=new Intpreguntas;
    intp->show();
    this->close();
}
