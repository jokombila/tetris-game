QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    i.cpp \
    j.cpp \
    l.cpp \
    main.cpp \
    mainwindow.cpp \
    o.cpp \
    objetgraphique.cpp \
    puits.cpp \
    s.cpp \
    t.cpp \
    tetromino.cpp \
    z.cpp

HEADERS += \
    Tetromino.h \
    i.h \
    j.h \
    l.h \
    mainwindow.h \
    o.h \
    objetgraphique.h \
    puits.h \
    s.h \
    t.h \
    z.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
