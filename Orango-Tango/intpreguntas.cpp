#include "intpreguntas.h"
#include "ui_intpreguntas.h"
#include <mainwindow.h>
#include <cbasedatos.h>
#include <QMessageBox>


Intpreguntas::Intpreguntas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intpreguntas)
{
    ui->setupUi(this);
    CBaseDatos BD;
    QVector <CPregunta> preguntas=BD.getPreguntas();
    for(int i=0;i<preguntas.length();i++){
        ui->listWidget->addItem(preguntas[i].getPregunta());
    }
}

Intpreguntas::~Intpreguntas()
{
    delete ui;
}

void Intpreguntas::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QMessageBox msg;
    CBaseDatos BD;
    QVector <CPregunta> preguntas=BD.getPreguntas();
    for(int i=0;i<preguntas.length();i++){
        if(preguntas[i].getPregunta()==item->text()){
            msg.setText(preguntas[i].getRespuesta());
        }
    }
    msg.exec();
}

void Intpreguntas::on_pushButton_clicked()
{
    MainWindow *intm=new MainWindow;
    intm->show();
    this->close();
}
