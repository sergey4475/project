#-------------------------------------------------
#
# Project created by QtCreator 2012-03-16T00:13:29
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += uitools

TARGET = mdi
TEMPLATE = app


SOURCES += main.cpp\
    mainform.cpp \
    frmlistspr.cpp \
    arm_admin.cpp \
    loginuser.cpp \
    global_module.cpp \
    table_models.cpp \
    frmuser.cpp \
    sqlprocessor.cpp

HEADERS  += mainform.h \
    frmlistspr.h \
    arm_admin.h \
    params.h \
    loginuser.h \
    global_module.h \
    table_models.h \
    frmuser.h \
    sqlprocessor.h

FORMS    += mainform.ui \
    frmlistspr.ui \
    arm_admin.ui \
    loginuser.ui \
    frmuser.ui

DESTDIR = ../bin

RESOURCES += \
    res.qrc

OTHER_FILES += \
    styles/default.qss \
    scripts/sqlite.sql \
    scripts/mysql.sql
