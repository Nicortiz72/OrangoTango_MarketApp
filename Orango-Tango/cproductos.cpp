#include "cproductos.h"
CProductos::CProductos(){}
CProductos::CProductos(QString Nom,QString Cod,QString Dir,QString Dim,QString Col,QString Pre,QString Cos,QString Can){
    m_nombre=Nom;
    m_codigo=Cod;
    m_descripcion=Dir;
    m_dimension=Dim;
    m_color=Col;
    m_precio=Pre;
    m_costo=Cos;
    m_cantidad=Can;
}
void CProductos::setNombre(QString Nom){m_nombre=Nom;}
void CProductos::setCodigo(QString Cod){m_codigo=Cod;}
void CProductos::setDescripcion(QString Dir){m_descripcion=Dir;}
void CProductos::setDimension(QString Dim){m_dimension=Dim;}
void CProductos::setColor(QString Col){m_color=Col;}
void CProductos::setPrecio(QString Pre){m_precio=Pre;}
void CProductos::setCosto(QString Cos){m_costo=Cos;}
void CProductos::setCantidad(QString Can){m_cantidad=Can;}
QString CProductos::getNombre(){return m_nombre;}
QString CProductos::getCodigo(){return m_codigo;}
QString CProductos::getDescripcion(){return m_descripcion;}
QString CProductos::getDimension(){return m_dimension;}
QString CProductos::getColor(){return m_color;}
int CProductos::getPrecio(){return m_precio.toInt();}
int CProductos::getCosto(){return m_costo.toInt();}
int CProductos::getCantidad(){return m_cantidad.toInt();}
