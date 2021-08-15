#include "cpregunta.h"

CPregunta::CPregunta(){}
CPregunta::CPregunta(QString pre, QString res)
{
    pregunta=pre;
    respuesta=res;
}
void CPregunta::setPregunta(QString pre){pregunta=pre;}
void CPregunta::setRespuesta(QString res){respuesta=res;}
QString CPregunta::getPregunta(){return pregunta;}
QString CPregunta::getRespuesta(){return respuesta;}
