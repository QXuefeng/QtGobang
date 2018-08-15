TEMPLATE = app

QT += qml quick

CONFIG += c++11



RESOURCES += qml.qrc

CONFIG(debug, debug|release) {
    DESTDIR = ../bin/Debug
    LIBS += -L../bin/Debug
} else {
    DESTDIR = ../bin/Release
    LIBS += -L../bin/Release
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    application.h \
    global.h \
    board/board.h \
    activity/activity.h \
    activity/localactivity.h \
    activity/robotactivity.h \
    ai/robot.h \
    activity/activityfactory.h

SOURCES += main.cpp
