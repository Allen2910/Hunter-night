#include "mainwindow.h"
#include "initalscreen.h"

#include <QApplication>
#include <goblin.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    MainWindow w;
    w.show();
    */
    initalScreen *game = new initalScreen();
    game->show();
    return a.exec();
}
