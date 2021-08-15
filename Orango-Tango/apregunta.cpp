#include "apregunta.h"
#include "ui_apregunta.h"
#include "cbasedatos.h"
#include "inempleados.h"


apregunta::apregunta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apregunta)
{
    ui->setupUi(this);
}

apregunta::~apregunta()
{
    delete ui;
}

void apregunta::on_pushButton_clicked()
{
   CBaseDatos BD;
   CPregunta pregunta(ui->pregunta->text(),ui->respuesta->text());
   BD.setPregunta(pregunta);
   inEmpleados *inte=new inEmpleados;
   inte->show();
   this->close();

}
