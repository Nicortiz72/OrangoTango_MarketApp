#ifndef CPROYECTOS_H
#define CPROYECTOS_H

#include <iostream>
#include <QString>
#include <QFile>
#include<QVector>
#include <QByteArray>
using namespace std;
class CProyectos{
private:
    QString m_descripcion;
    QString m_costo;
    QString m_precio;
    QString m_usuario;
public:
    CProyectos();
    CProyectos(QString,QString,QString,QString);
    void setDescripcion(QString);
    void setCosto(QString);
    void setPrecio(QString);
    QString getDescripcion();
    QString getCosto();
    QString getPrecio();
    QString getUsuario();
    void setUsuario(QString);
};

#endif // CPROYECTOS_H
