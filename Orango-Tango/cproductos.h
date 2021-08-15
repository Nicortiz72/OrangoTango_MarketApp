#ifndef CPRODUCTOS_H
#define CPRODUCTOS_H
#include <iostream>
#include <QString>
#include <QFile>
#include<QVector>
#include <QByteArray>
using namespace std;

class CProductos{
private:
    QString m_nombre;
    QString m_codigo;
    QString m_descripcion;
    QString m_dimension;
    QString m_color;
    QString m_precio;
    QString m_costo;
    QString m_cantidad;
public:
    CProductos();
    CProductos(QString,QString,QString,QString,QString,QString,QString,QString);
    void setNombre(QString);
    void setCodigo(QString);
    void setDescripcion(QString);
    void setDimension(QString);
    void setColor(QString);
    void setPrecio(QString);
    void setCosto(QString);
    void setCantidad(QString);
    QString getNombre();
    QString getCodigo();
    QString getDescripcion();
    QString getDimension();
    QString getColor();
    int getPrecio();
    int getCosto();
    int getCantidad();

};

#endif // CPRODUCTOS_H
