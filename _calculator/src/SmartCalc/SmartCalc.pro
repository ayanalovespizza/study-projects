QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QMAKE_CXX = g++
CONFIG -= clang_code_model

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calculate/helpers.c \
    ../calculate/polish.c \
    ../calculate/validators.c \
    credit.cpp \
    deposit.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../calculate/headers/helpers.h \
    ../calculate/headers/polish.h \
    ../calculate/headers/validators.h \
    graph.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    graph.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
