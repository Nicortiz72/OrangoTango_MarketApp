#include "intusuario.h"
#include "ui_intusuario.h"
#include "cbasedatos.h"
#include <QMessageBox>
#include <cregistro.h>
#include <cclientes.h>
#include "carro.h"
#include <mainwindow.h>
#include <intproyecto.h>
#include "pproyectos.h"

Intusuario::Intusuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Intusuario)
{
    ui->setupUi(this);
    CRegistro reg;
    QString cliente = reg.getCliente();
    ui->label_5->setText(cliente);
    CBaseDatos BD;
    QVector <CProductos> productos = BD.getInventario();
    for(int i=0; i<productos.length(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(productos[i].getCodigo()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(productos[i].getNombre()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(productos[i].getDescripcion()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(productos[i].getDimension()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4, new QTableWidgetItem(productos[i].getColor()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5, new QTableWidgetItem(QString::number(productos[i].getPrecio())+" $"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6, new QTableWidgetItem(QString::number(productos[i].getCantidad())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7, new QTableWidgetItem("AÑADIR"));
    }
    QVector <CProyectos> proyectos = BD.getProyectos();
    bool HayProyectos=0;
    for(int i=0;i<proyectos.length();i++){
        if(proyectos[i].getUsuario()==cliente) HayProyectos=1;
    }
    if(HayProyectos){
        QMessageBox msg;
        msg.setText("Tienes respuesta a tus proyectos solicitados. ¿Deseas verlos ahora?");
        msg.addButton("Si",QMessageBox::AcceptRole);
        msg.addButton("No",QMessageBox::RejectRole);
        int nproyectos = msg.exec();
        if(nproyectos==0){
            PProyectos *intp=new PProyectos(0,this);
            intp->show();
            this->showMinimized();
        }
    }
}

Intusuario::~Intusuario()
{
    delete ui;
}


void Intusuario::on_tableWidget_itemClicked(QTableWidgetItem *item)
{   
    int n=item->row();
    if(item->text()=="AÑADIR"){
        QMessageBox msg;
        if(ui->tableWidget->item(n,6)->text().toInt()>0){
            CBaseDatos BD;
            QVector <CProductos> productos = BD.getInventario();
            productos[n].setCantidad("1");
            CRegistro reg;
            if(!reg.verificar(productos[n].getCodigo(),QString::number(productos[n].getCantidad()))){
                reg.AgregarCarrito(productos[n]);
                msg.setText("Producto añadido.");
                msg.exec();
                ui->contador->setText(QString::number(ui->contador->text().toInt()+1));
                ui->tableWidget->setItem(n,6,new QTableWidgetItem(QString::number(ui->tableWidget->item(n,6)->text().toInt()-1)));
            }else{
                msg.setText("Error al añadir producto.");
                msg.exec();
            }
        }else{
            msg.setText("No quedan existencias de este producto.");
            msg.exec();
        }
    }
}

void Intusuario::on_pushButton_clicked()
{
    Carro *carro = new Carro;
    carro->show();
    this->close();
}

void Intusuario::on_pushButton_2_clicked()
{
    MainWindow *mainw = new MainWindow;
    mainw->show();
    this->close();
}

void Intusuario::on_pushButton_3_clicked()
{
    intproyecto *intp=new intproyecto;
    intp->show();
}
