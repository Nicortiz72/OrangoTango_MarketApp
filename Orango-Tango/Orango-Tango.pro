#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T09:11:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Orango-Tango
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    registro.cpp \
    intusuario.cpp \
    cusuario.cpp \
    cproyectos.cpp \
    cproductos.cpp \
    cbasedatos.cpp \
    cfacade.cpp \
    ccarrito.cpp \
    cclientes.cpp \
    cregistro.cpp \
    carro.cpp \
    inempleados.cpp \
    aempleado.cpp \
    intproyecto.cpp \
    pproyectos.cpp \
    aproducto.cpp \
    intpreguntas.cpp \
    cpregunta.cpp \
    apregunta.cpp

HEADERS += \
        mainwindow.h \
    registro.h \
    intusuario.h \
    cusuario.h \
    cproyectos.h \
    cproductos.h \
    cbasedatos.h \
    cfacade.h \
    ccarrito.h \
    cclientes.h \
    cregistro.h \
    carro.h \
    inempleados.h \
    aempleado.h \
    intproyecto.h \
    pproyectos.h \
    aproducto.h \
    intpreguntas.h \
    cpregunta.h \
    apregunta.h

FORMS += \
        mainwindow.ui \
    registro.ui \
    intusuario.ui \
    carro.ui \
    inempleados.ui \
    aempleado.ui \
    intproyecto.ui \
    pproyectos.ui \
    aproducto.ui \
    intpreguntas.ui \
    apregunta.ui
