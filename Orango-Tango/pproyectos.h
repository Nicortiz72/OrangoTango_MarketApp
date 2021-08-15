#ifndef PPROYECTOS_H
#define PPROYECTOS_H
#include <QTableWidgetItem>
#include <QWidget>
#include <intusuario.h>
namespace Ui {
class PProyectos;
}

class PProyectos : public QWidget
{
    Q_OBJECT

public:
    explicit PProyectos(QWidget *parent = 0,Intusuario *intut=NULL);
    ~PProyectos();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::PProyectos *ui;
    Intusuario *intu;
};

#endif // PPROYECTOS_H
