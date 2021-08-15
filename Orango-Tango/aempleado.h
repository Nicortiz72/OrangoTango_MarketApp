#ifndef AEMPLEADO_H
#define AEMPLEADO_H

#include <QWidget>

namespace Ui {
class AEmpleado;
}

class AEmpleado : public QWidget
{
    Q_OBJECT

public:
    explicit AEmpleado(QWidget *parent = 0);
    ~AEmpleado();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AEmpleado *ui;
};

#endif // AEMPLEADO_H
