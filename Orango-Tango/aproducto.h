#ifndef APRODUCTO_H
#define APRODUCTO_H

#include <QWidget>

namespace Ui {
class AProducto;
}

class AProducto : public QWidget
{
    Q_OBJECT

public:
    explicit AProducto(QWidget *parent = 0);
    ~AProducto();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AProducto *ui;
};

#endif // APRODUCTO_H
