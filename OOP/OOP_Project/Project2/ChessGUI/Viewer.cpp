#include <stdexcept>
#include <iostream>
#include <string>
#include "Viewer.h"
#include "GameManager.h"
#include "chessgui.h"
#include <QApplication>



using std::cin;
using std::cout;
using std::endl;
using std::string;

Viewer::Viewer() {
    game_manager = nullptr;
}

Viewer::Viewer(GameManager* gm_from) {
    game_manager = gm_from;
}

Viewer::~Viewer() {

}

int Viewer::start(){

    int argc = 0;
    char *argv[] = {};
    QApplication a(argc,argv);
    ChessGUI w;
    w.show();
    return a.exec();

}

void Viewer::render_board() {

}

void Viewer::render_main() {

}
