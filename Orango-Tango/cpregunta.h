#ifndef CPREGUNTA_H
#define CPREGUNTA_H
#include <QString>

class CPregunta
{
private:
    QString pregunta;
    QString respuesta;
public:
    CPregunta();
    CPregunta(QString,QString);
    void setPregunta(QString);
    void setRespuesta(QString);
    QString getPregunta();
    QString getRespuesta();
};

#endif // CPREGUNTA_H
