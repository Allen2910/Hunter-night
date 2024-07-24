#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "goblin.h"
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    goblin goblin1;
    QPixmap pixmap_goblin1 = goblin1.get_goblin_image();
    if(pixmap_goblin1.isNull()){
        qDebug("failed to load");
    }
    int width = ui->goblin1->width();
    int height = ui->goblin1->height();
    ui->goblin1->setPixmap(pixmap_goblin1.scaled(width,height,Qt::KeepAspectRatioByExpanding));

}

MainWindow::~MainWindow()
{
    delete ui;
}
