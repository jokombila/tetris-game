QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include

SOURCES += \
   src/main.cpp \
   src/mainwindow.cpp \
   src/objetgraphique.cpp \
   src/partie.cpp \
   src/puits.cpp \
   src/tetromino.cpp \
   src/i.cpp \
   src/j.cpp \
   src/l.cpp \
   src/o.cpp \
   src/s.cpp \
   src/t.cpp \
   src/z.cpp


HEADERS += \
    include/Tetromino.h \
    include/i.h \
    include/j.h \
    include/l.h \
    include/mainwindow.h \
    include/o.h \
    include/objetgraphique.h \
    include/partie.h \
    include/puits.h \
    include/s.h \
    include/t.h \
    include/z.h


FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
