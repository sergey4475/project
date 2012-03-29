#-------------------------------------------------
#
# Project created by QtCreator 2012-03-16T00:13:29
#
#-------------------------------------------------

INCLUDEPATH += "../widgets/ToolBar" \

QT       += core gui sql

TARGET = mdi
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    frmlistspr.cpp \
    arm_admin.cpp \
    loginuser.cpp \
    global_module.cpp \
    table_models.cpp

HEADERS  += mainform.h \
    frmlistspr.h \
    arm_admin.h \
    params.h \
    loginuser.h \
    global_module.h \
    table_models.h

FORMS    += mainform.ui \
    frmlistspr.ui \
    arm_admin.ui \
    loginuser.ui

DESTDIR = ../bin

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    styles/default.qss
