#include "cclientes.h"

CClientes::CClientes(QString Nom, QString Ap, QString FN, bool Sex, QString EC, QString ID, QString TCred, QString Direc, QString Tel, QString Cel, QString Correo, QString Us, QString Pass, QString PSecret)
    : CUsuario(Nom,Ap,FN,Sex,EC,ID,TCred,Direc,Tel,Cel,Correo,Us,Pass,PSecret){
    m_Carrito= new CCarrito;
}

CClientes::~CClientes(){}

void CClientes::IngresarProducto(CProductos producto){
   m_Carrito->IngresarProducto(producto);
}

void CClientes::EliminarProducto(CProductos producto){
    m_Carrito->EliminarProducto(producto);
}

CCarrito* CClientes::getCarrito(){
    return m_Carrito;
}
