#ifndef CCARRITO_H
#define CCARRITO_H
#include <cfacade.h>

class CCarrito{
private:
    QVector <CProductos> m_Productos;
    CFacade fachada;
    int m_CostoAcumulado;
public:
    CCarrito();
    ~CCarrito();

    void IngresarProducto(CProductos);
    void EliminarProducto(CProductos);
    void CalcularCostoAcum();
    int getCostoAcum();
    QVector <CProductos> getProductos();
    void setCarrito(QVector <CProductos>);
};

#endif // CCARRITO_H
