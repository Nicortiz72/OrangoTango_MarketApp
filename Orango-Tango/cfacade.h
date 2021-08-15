#ifndef CFACADE_H
#define CFACADE_H
#include <cproductos.h>
#include <cbasedatos.h>
class CFacade{
public:
    CFacade();
    QVector<CProductos> getProductos();
    void setProductos(QVector<CProductos>);
};

#endif // CFACADE_H
