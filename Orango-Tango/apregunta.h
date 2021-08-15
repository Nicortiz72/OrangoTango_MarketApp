#ifndef APREGUNTA_H
#define APREGUNTA_H

#include <QWidget>

namespace Ui {
class apregunta;
}

class apregunta : public QWidget
{
    Q_OBJECT

public:
    explicit apregunta(QWidget *parent = 0);
    ~apregunta();

private slots:
    void on_pushButton_clicked();

private:
    Ui::apregunta *ui;
};

#endif // APREGUNTA_H
