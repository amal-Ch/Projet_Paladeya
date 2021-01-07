QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnement.cpp \
    connexion.cpp \
    exportexcelobject.cpp \
    main.cpp \
    mainwindow.cpp \
    municipalite.cpp \
    statistique.cpp

HEADERS += \
    abonnement.h \
    connexion.h \
    exportexcelobject.h \
    mainwindow.h \
    municipalite.h \
    statistique.h

FORMS += \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
