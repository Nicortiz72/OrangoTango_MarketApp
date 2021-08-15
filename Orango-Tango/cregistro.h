#ifndef CREGISTRO_H
#define CREGISTRO_H
#include<cbasedatos.h>
#include <ccarrito.h>

class CRegistro{
private:
    QFile *RegTmp;
    QFile *Reg;
public:
    CRegistro();
    CProductos Buscar(QString, QString);
    void setCliente(QString);
    void setCarrito(CCarrito);
    CCarrito getCarrito();
    QString getCliente();
    void AgregarCarrito(CProductos);
    void EliminarCarrito(CProductos);
    bool verificar(QString , QString);
    QVector <CProductos> getProductos();
    void Quitar(CProductos);
    void Facturar(bool);
    QString getNfactura();
    QString getVentas(CProductos);
    void setVentas(CProductos);
    void sumaNfactura();
    void FacturarProyecto(CProyectos);
};

#endif // CREGISTRO_H
