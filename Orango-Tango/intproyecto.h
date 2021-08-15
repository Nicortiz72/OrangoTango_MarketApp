#ifndef INTPROYECTO_H
#define INTPROYECTO_H

#include <QWidget>

namespace Ui {
class intproyecto;
}

class intproyecto : public QWidget
{
    Q_OBJECT

public:
    explicit intproyecto(QWidget *parent = 0);
    ~intproyecto();

private slots:
    void on_pushButton_clicked();

private:
    Ui::intproyecto *ui;
};

#endif // INTPROYECTO_H
