#ifndef CBASEDATOS_H
#define CBASEDATOS_H
#include <iostream>
#include <QString>
#include <QFile>
#include<QVector>
#include <QByteArray>
#include <cproductos.h>
#include <cproyectos.h>
#include <cusuario.h>
#include <QTextStream>
#include <cpregunta.h>

using namespace std;

class CBaseDatos{
private:
    QFile* user;
    QFile* Clientes;
    QFile* Proyectos;
    QFile* Inventario;
    QFile* Empleados;
    QFile* preguntas;
public:
    CBaseDatos();
    void ActualizarUser(QString,QString);
    bool VerificarUser(QString,QString);
    CUsuario getCliente(QString);
    void ActualizarClientes(QString, QString, QString, bool, QString, QString, QString, QString , QString, QString, QString , QString, QString, QString);
    QString InCrip(QString);
    QString DeCrip(QString);
    QVector<CProductos> getInventario();
    void ActualizarInventario(QString,QString,QString,QString,QString,QString,QString,QString);
    void ActualizarProyectos(QString,QString,QString,QString);
    QVector<CProyectos> getProyectos();
    void setInventario(QVector<CProductos>);

    void ActualizarEpleadosLogin(QString,QString);
    bool VerificarEmpleados(QString,QString);
    QVector<CUsuario> getClientes();
    QVector<CUsuario> getEmpleados();
    void setProyectos(QString,QString, QString);
    void setPregunta(CPregunta);
    QVector <CPregunta> getPreguntas();
    void recreatePreguntas(QString, QString);

};

#endif // CBASEDATOS_H
