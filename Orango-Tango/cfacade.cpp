#include "cfacade.h"

CFacade::CFacade(){
    CBaseDatos base;
}
QVector<CProductos> CFacade::getProductos(){
    CBaseDatos BD;
    return BD.getInventario();
}
void CFacade::setProductos(QVector<CProductos> prod){
    CBaseDatos base;
    base.setInventario(prod);
}
