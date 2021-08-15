#include "ccarrito.h"
#include <QMessageBox>
CCarrito::CCarrito(){
    m_CostoAcumulado = 0;
    m_Productos.clear();
}

CCarrito::~CCarrito(){}

void CCarrito::IngresarProducto(CProductos producto){
    CBaseDatos BD;
    QVector <CProductos> v = BD.getInventario();
    int a=0,i;
    QMessageBox msg;

    for(i=0; i<m_Productos.length();i++){
        msg.setText(QString::number(m_Productos[i].getCantidad()));
        msg.exec();
        if(m_Productos[i].getNombre() == producto.getNombre()){
            a=1;
            break;
        }
    }
    for(int j=0; j<v.length();j++){
        if(producto.getNombre() == v[j].getNombre()){
            if(v[j].getCantidad() >= producto.getCantidad()){
                if(a)
                    m_Productos[i].setCantidad(QString::number(m_Productos[i].getCantidad() + producto.getCantidad()));
                else
                    m_Productos.append(producto);
                v[j].setCantidad(QString::number(v[j].getCantidad()-producto.getCantidad()));
            }
        }
    }
    fachada.setProductos(v);
}

void CCarrito::EliminarProducto(CProductos producto){
    QVector <CProductos> v = fachada.getProductos();
    for(int i=0; i<m_Productos.length();i++){
        if(m_Productos[i].getNombre() == producto.getNombre()){
            if(m_Productos[i].getCantidad() >= producto.getCantidad()){
                for(int i=0; i<v.length();i++){
                    if(producto.getNombre() == v[i].getNombre()){
                        m_Productos[i].setCantidad(QString::number(m_Productos[i].getCantidad()-m_Productos[i].getCantidad()));
                        v[i].setCantidad(QString::number(v[i].getCantidad()+producto.getCantidad()));
                        if(m_Productos[i].getCantidad()<=0)
                            m_Productos.remove(i);
                    }
                }
            }
            break;
        }
    }
    fachada.setProductos(v);
}

void CCarrito::CalcularCostoAcum(){
    int acum=0;
    for(int j=1; j<=m_Productos.length();j++){
        acum += (m_Productos[j].getPrecio() * m_Productos[j].getCantidad());
    }
    m_CostoAcumulado = acum;

}

int CCarrito::getCostoAcum(){
    return m_CostoAcumulado;
}
QVector <CProductos> CCarrito::getProductos(){
    return m_Productos;
}
void CCarrito::setCarrito(QVector <CProductos> car){
    m_Productos=car;
}
