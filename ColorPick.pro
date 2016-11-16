#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T23:55:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorPick
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32 {
    RC_FILE = colorpick.rc
}
macx {
      # Copy the custom Info.plist to the app bundle
    QMAKE_INFO_PLIST = Info.plist
    # Icon is mandatory for submission
    ICON = icon.icns
}
