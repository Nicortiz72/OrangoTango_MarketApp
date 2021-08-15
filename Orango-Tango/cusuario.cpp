#include "cusuario.h"
CUsuario::CUsuario(){}
CUsuario::~CUsuario(){}

CUsuario::CUsuario(QString Nom, QString Ap, QString FN, bool Sex, QString EC, QString ID, QString TCred, QString Direc, QString Tel, QString Cel, QString Correo, QString Us, QString Pass, QString PSecret){
    m_Nombres = Nom;
    m_Apellidos = Ap;
    m_FechaNacimiento = FN;
    m_Sexo = Sex;
    m_EstCivil = EC;
    m_ID = ID;
    m_TCredito = TCred;

    m_Direccion = Direc;
    m_Telefono = Tel;
    m_Celular = Cel;
    m_Correo = Correo;

    m_Usuario = Us;
    m_Cont = Pass;
    m_PSecreta = PSecret;
}

QString CUsuario::getNombres(){return m_Nombres;}
void CUsuario::setNombres(QString Nom){m_Nombres = Nom;}
QString CUsuario::getApellidos(){return m_Apellidos;}
void CUsuario::setApellidos(QString Ap){m_Apellidos = Ap;}
QString CUsuario::getFechaN(){return m_FechaNacimiento;}
void CUsuario::setFechaN(QString FN){m_FechaNacimiento = FN;}
bool CUsuario::getSexo(){return m_Sexo;}
void CUsuario::setSexo(bool s){m_Sexo = s;}
QString CUsuario::getEstCivil(){return m_EstCivil;}
void CUsuario::setEstCivil(QString EC){m_EstCivil = EC;}
QString CUsuario::getID(){return m_ID;}
void CUsuario::setID(long int id){m_ID = id;}
QString CUsuario::getTCredito(){return m_TCredito;}
void CUsuario::setTCredito(long int TC){m_TCredito = TC;}

QString CUsuario::getDireccion(){return m_Direccion;}
void CUsuario::setDireccion(QString dir){m_Direccion = dir;}
QString CUsuario::getTel(){return m_Telefono;}
void CUsuario::setTel(long int tel){m_Telefono = tel;}
QString CUsuario::getCelular(){return m_Celular;}
void CUsuario::setCelular(long int cel){m_Celular = cel;}
QString CUsuario::getCorreo(){return m_Correo;}
void CUsuario::setCorreo(QString correo){m_Correo = correo;}

QString CUsuario::getUsuario(){return m_Usuario;}
void CUsuario::setUsuario(QString usuario){m_Usuario = usuario;}
QString CUsuario::getPassw(){return m_Cont;}
void CUsuario::setPassw(QString pass){m_Cont = pass;}
QString CUsuario::getPSecreta(){return m_PSecreta;}
void CUsuario::setPSecreta(QString PS){m_PSecreta = PS;}
