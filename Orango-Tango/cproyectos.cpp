#include "cproyectos.h"
CProyectos::CProyectos(){}
CProyectos::CProyectos(QString usuario,QString Des,QString Cos,QString Pre){
    m_usuario=usuario;
    m_descripcion=Des;
    m_costo=Cos;
    m_precio=Pre;
}
void CProyectos::setDescripcion(QString Des){m_descripcion=Des;}
void CProyectos::setCosto(QString Cos){m_costo=Cos;}
void CProyectos::setPrecio(QString Pre){m_precio=Pre;}
void CProyectos::setUsuario(QString nom){m_usuario=nom;}
QString CProyectos::getDescripcion(){return m_descripcion;}
QString CProyectos::getCosto(){return m_costo;}
QString CProyectos::getPrecio(){return m_precio;}
QString CProyectos::getUsuario(){return m_usuario;}
