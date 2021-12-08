QT       += core gui sql axcontainer printsupport
QT       += core gui
QT       += sql
QT       += core gui multimedia multimediawidgets
QT += printsupport
QT       += core gui network
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    dialog.cpp \
    dialog_perso.cpp \
    dialog_v.cpp \
    email.cpp \
    excel.cpp \
    gdp.cpp \
    gestion_animaux.cpp \
    gestiondesproduits.cpp \
    login.cpp \
    login_bd.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    statistique.cpp \
    visiteurs.cpp

HEADERS += \
    connexion.h \
    dialog.h \
    dialog_perso.h \
    dialog_v.h \
    email.h \
    excel.h \
    gdp.h \
    gestion_animaux.h \
    gestiondesproduits.h \
    login.h \
    login_bd.h \
    mainwindow.h \
    personnel.h \
    qcustomplot.h \
    smtp.h \
    statistique.h \
    visiteurs.h

FORMS += \
    dialog.ui \
    dialog_perso.ui \
    dialog_v.ui \
    email.ui \
    gestiondesproduits.ui \
    login.ui \
    mainwindow.ui \
    statistique.ui

#Client ICON
RC_ICONS = g.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    AA.jpg \
    F.jpg \
    FF.jpg \
    MW.jpg \
    PP.jpg \
    SmartParc.png \
    g.ico
