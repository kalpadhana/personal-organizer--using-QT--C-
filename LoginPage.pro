QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categorybudgeting.cpp \
    charts.cpp \
    dashboard.cpp \
    dialog.cpp \
    expwin.cpp \
    main.cpp \
    mainwindow.cpp \
    registerpage.cpp \
    reports.cpp \
    schedule.cpp

HEADERS += \
    categorybudgeting.h \
    charts.h \
    dashboard.h \
    dialog.h \
    expwin.h \
    mainwindow.h \
    registerpage.h \
    reports.h \
    schedule.h \
    usersession.h

FORMS += \
    categorybudgeting.ui \
    charts.ui \
    dashboard.ui \
    dialog.ui \
    expwin.ui \
    mainwindow.ui \
    registerpage.ui \
    reports.ui \
    schedule.ui

RESOURCES += \
    src.qrc

DISTFILES +=



