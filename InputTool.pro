#-------------------------------------------------
#
# Project created by QtCreator 2014-08-15T14:34:50
#
#-------------------------------------------------

QT       += core gui sql network
QT       += axcontainer
#语言输入所需模块
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InputTool
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    frminput.cpp \
    frmnum.cpp\
    inputform.cpp \
    adddatabase.cpp\
    audio.cpp\
    speech.cpp\
    http.cpp\
    DlgMain.cpp\
    hand/handsinput.cpp

HEADERS  += frmmain.h \
    frminput.h \
    frmnum.h\
    inputform.h \
    adddatabase.h\
    audio.h\
    speech.h\
    http.h\
    DlgMain.h\
    hand/handsinput.h

FORMS    += frmmain.ui \
    frmnum.ui \
    frminput.ui\
    inputform.ui \
    adddatabase.ui\
    DlgMain.ui

INCLUDEPATH +=C:\MicrosoftTablet\Include

MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = bin
