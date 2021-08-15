#include "intproyecto.h"
#include "ui_intproyecto.h"
#include <cbasedatos.h>
#include <cregistro.h>
#include <QMessageBox>
intproyecto::intproyecto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::intproyecto)
{
    ui->setupUi(this);
}

intproyecto::~intproyecto()
{
    delete ui;
}

void intproyecto::on_pushButton_clicked()
{
    CBaseDatos BD;
    QMessageBox msg;
    msg.setText("Solicitud enviada.");
    msg.exec();
    CRegistro reg;
    BD.ActualizarProyectos(reg.getCliente(),ui->texto->text(),"0","0");
    this->close();
}
