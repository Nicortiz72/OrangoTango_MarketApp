#include "carro.h"
#include "ui_carro.h"
#include <cregistro.h>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include <intusuario.h>
Carro::Carro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Carro)
{
    ui->setupUi(this);
    CRegistro reg;
    QVector <CProductos> carro=reg.getProductos();
    int suma=0;
    for(int i=0; i<carro.length(); i++){
        suma+=carro[i].getCantidad() * carro[i].getPrecio();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(carro[i].getCodigo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(carro[i].getNombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(carro[i].getDescripcion()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(carro[i].getDimension()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(carro[i].getColor()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5, new QTableWidgetItem(QString::number(carro[i].getPrecio())+" $"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6, new QTableWidgetItem(QString::number(carro[i].getCantidad())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7, new QTableWidgetItem(QString::number(carro[i].getCantidad() * carro[i].getPrecio())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8, new QTableWidgetItem("ELIMINAR"));
    }
    ui->sub->setText(QString::number(suma));
    ui->total->setText(QString::number(suma));
}

Carro::~Carro()
{
    delete ui;
}

void Carro::on_pushButton_2_clicked()
{
    ui->pushButton_2->setDisabled(1);
    ui->pushButton->setDisabled(1);
    ui->tableWidget->setDisabled(1);
    srand (time(NULL));
    bool des=0;
    int x=rand()%100;
    if(x<=50){
        ui->des->setText(QString::number(ui->sub->text().toInt()/10));
        ui->total->setText(QString::number(ui->sub->text().toInt()-ui->des->text().toInt()));
        des=1;
    }
    CRegistro reg;
    CBaseDatos BD;
    QString nfac=reg.getNfactura();
    QMessageBox msg;
    QVector<CProductos> inv=BD.getInventario();
    QVector<CProductos> pro=reg.getProductos();
    int i,j;
    for(i=0;i<pro.length();i++){
        for(j=0;j<inv.length();j++){
            if(pro[i].getCodigo()==inv[j].getCodigo()){
                inv[j].setCantidad(QString::number(inv[j].getCantidad()-pro[i].getCantidad()));
            }
        }
    }
    BD.setInventario(inv);
    for(i=0;i<pro.length();i++)reg.setVentas(pro[i]);
    reg.Facturar(des);
    msg.setText("La Factura se a generado como:\nFacturaN"+nfac+".txt");
    msg.exec();
    Intusuario *intu=new Intusuario;
    intu->show();
    this->close();

}

void Carro::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int n=item->row();
    if(item->text()=="ELIMINAR"){
        if(ui->tableWidget->takeItem(n,6)->text().toInt()>0){
            CRegistro reg;
            QVector <CProductos> productos=reg.getProductos();
            reg.Quitar(productos[n]);
            QVector <CProductos> carro=reg.getProductos();
            ui->tableWidget->setItem(n,7,new QTableWidgetItem(QString::number(carro[n].getCantidad()*carro[n].getPrecio())));
            ui->tableWidget->setItem(n,6,new QTableWidgetItem(QString::number(carro[n].getCantidad())));
            ui->sub->setText(QString::number(ui->sub->text().toInt()-carro[n].getPrecio()));
            ui->total->setText(QString::number(ui->total->text().toInt()-carro[n].getPrecio()));
        }
    }
}

void Carro::on_pushButton_clicked()
{
    ui->pushButton_2->setDisabled(0);
}
