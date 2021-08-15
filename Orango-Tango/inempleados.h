#ifndef INEMPLEADOS_H
#define INEMPLEADOS_H

#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class inEmpleados;
}

class inEmpleados : public QWidget
{
    Q_OBJECT

public:
    explicit inEmpleados(QWidget *parent = 0);
    ~inEmpleados();

private slots:
    void on_Productos_clicked();

    void on_pushButton_clicked();

    void on_proyectos_clicked();

    void on_clientes_clicked();

    void on_empleados_clicked();

    void on_aempleado_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_aproducto_clicked();

    void on_clientes_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::inEmpleados *ui;
};

#endif // INEMPLEADOS_H
