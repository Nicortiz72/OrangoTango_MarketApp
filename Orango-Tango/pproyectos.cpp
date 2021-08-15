#include "pproyectos.h"
#include "ui_pproyectos.h"
#include <cregistro.h>
#include <QMessageBox>
#include "intusuario.h"

PProyectos::PProyectos(QWidget *parent,Intusuario *intut) :
    QWidget(parent),
    ui(new Ui::PProyectos)
{
    ui->setupUi(this);
    intu=intut;
    CBaseDatos BD;
    CRegistro reg;
    QString cliente = reg.getCliente();
    QVector <CProyectos> proyectosT = BD.getProyectos();
    QVector <CProyectos> proyectos;
    for(int i=0;i<proyectosT.length();i++){
        if(cliente==proyectosT[i].getUsuario()){
            proyectos.append(proyectosT[i]);
        }
    }
    ui->tableWidget->setRowCount(proyectos.length());
    for(int i=0; i<proyectos.length(); i++){
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(proyectos[i].getDescripcion()));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(proyectos[i].getPrecio()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem("FACTURAR"));
    }
}

PProyectos::~PProyectos()
{
    delete ui;
}

void PProyectos::on_pushButton_clicked()
{
    intu->showNormal();
    this->close();
}

void PProyectos::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int n=item->row();
    QMessageBox msg;
    if(item->text()=="FACTURAR"){
        CRegistro reg;
        CBaseDatos BD;
        QString nfac=reg.getNfactura();
        QString precio=ui->tableWidget->item(n,1)->text();
        QString cliente = reg.getCliente();
        QVector <CProyectos> proyectosT = BD.getProyectos();
        QVector <CProyectos> proyectos;
        for(int i=0;i<proyectosT.length();i++){
            if(cliente==proyectosT[i].getUsuario()){
                proyectos.append(proyectosT[i]);
            }
        }
        reg.FacturarProyecto(proyectos[n]);
        msg.setText("La Factura se a generado como:\nFacturaN"+nfac+".txt");
        msg.exec();

    }else{
        if(item->column()==0){
            msg.setText(item->text());
            msg.exec();
        }
    }
}
