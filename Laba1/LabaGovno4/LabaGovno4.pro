QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    hexagon.cpp \
    main.cpp \
    parallelogram.cpp \
    rectangle.cpp \
    romb.cpp \
    shape.cpp \
    square.cpp \
    star5.cpp \
    star6.cpp \
    star8.cpp \
    triangle.cpp \
    widget.cpp

HEADERS += \
    circle.h \
    hexagon.h \
    parallelogram.h \
    rectangle.h \
    romb.h \
    shape.h \
    square.h \
    star5.h \
    star6.h \
    star8.h \
    triangle.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
