QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    GameManager.cpp \
    GameSetting.cpp \
    Piece.cpp \
    Viewer.cpp \
    main.cpp \
    chessgui.cpp

HEADERS += \
    Board.h \
    GameManager.h \
    GameSetting.h \
    Piece.h \
    Player.h \
    Viewer.h \
    chessgui.h

FORMS += \
    chessgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    chess.qrc \
    chess.qrc

DISTFILES += \
    .gitignore \
    ChessGUI.pro.user
