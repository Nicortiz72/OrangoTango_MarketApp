#ifndef CUSUARIO_H
#define CUSUARIO_H
#include <iostream>
#include <QString>
#include <QFile>
#include<QVector>
#include <QByteArray>
using namespace std;

class CUsuario{
protected:
    //Informacion personal
    QString m_Nombres;
    QString m_Apellidos;
    QString m_FechaNacimiento;
    bool m_Sexo;
    QString m_EstCivil;
    QString m_ID;
    QString m_TCredito;

    //Contacto

    QString m_Direccion;
    QString m_Telefono;
    QString m_Celular;
    QString m_Correo;

    //Datos de la cuenta

    QString m_Usuario;
    QString m_Cont;
    QString m_PSecreta;

public:
    CUsuario();
    CUsuario(QString Nom, QString Ap, QString FN, bool Sex, QString EC, QString ID, QString TCred, QString Direc, QString Tel, QString Cel, QString Correo, QString Us, QString Pass, QString PSecret);
    ~CUsuario();

    QString getNombres();
    void setNombres(QString);
    QString getApellidos();
    void setApellidos(QString);
    QString getFechaN();
    void setFechaN(QString);
    bool getSexo();
    void setSexo(bool);
    QString getEstCivil();
    void setEstCivil(QString);
    QString getID();
    void setID(long int);
    QString getTCredito();
    void setTCredito(long int);

    QString getDireccion();
    void setDireccion(QString);
    QString getTel();
    void setTel(long int);
    QString getCelular();
    void setCelular(long int);
    QString getCorreo();
    void setCorreo(QString);

    QString getUsuario();
    void setUsuario(QString);
    QString getPassw();
    void setPassw(QString);
    QString getPSecreta();
    void setPSecreta(QString);
};

#endif // CUSUARIO_H
