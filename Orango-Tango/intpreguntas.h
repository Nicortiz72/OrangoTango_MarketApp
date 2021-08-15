#ifndef INTPREGUNTAS_H
#define INTPREGUNTAS_H
#include <QListWidgetItem>
#include <QWidget>

namespace Ui {
class Intpreguntas;
}

class Intpreguntas : public QWidget
{
    Q_OBJECT

public:
    explicit Intpreguntas(QWidget *parent = 0);
    ~Intpreguntas();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::Intpreguntas *ui;
};

#endif // INTPREGUNTAS_H
