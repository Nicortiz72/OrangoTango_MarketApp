#ifndef CARRO_H
#define CARRO_H

#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class Carro;
}

class Carro : public QWidget
{
    Q_OBJECT

public:
    explicit Carro(QWidget *parent = 0);
    ~Carro();

private slots:
    void on_pushButton_2_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::Carro *ui;
};

#endif // CARRO_H
