#ifndef CCLIENTES_H
#define CCLIENTES_H

#include<cusuario.h>
#include <ccarrito.h>
class CClientes : public CUsuario
{
private:
    CCarrito* m_Carrito;
public:
    CClientes(QString Nom, QString Ap, QString FN, bool Sex, QString EC, QString ID, QString TCred, QString Direc, QString Tel, QString Cel, QString Correo, QString Us, QString Pass, QString PSecret);
    ~CClientes();

    void IngresarProducto(CProductos);
    void EliminarProducto(CProductos);
    CCarrito* getCarrito();
};

#endif // CCLIENTES_H
