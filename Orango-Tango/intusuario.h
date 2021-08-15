#ifndef INTUSUARIO_H
#define INTUSUARIO_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class Intusuario;
}

class Intusuario : public QWidget
{
    Q_OBJECT

public:
    explicit Intusuario(QWidget *parent = 0);
    ~Intusuario();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Intusuario *ui;
};

#endif // INTUSUARIO_H
