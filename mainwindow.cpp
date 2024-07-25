#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "goblin.h"
#include "main_character.h"
#include <QPixmap>
#include <QMessageBox>
#include <QMouseEvent>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // put the hunter image on mainwindow
    QPixmap pixmap_hunter = hunter.get_main_character_image();
    if(pixmap_hunter.isNull()){
        qDebug("failed to load pixmap_hunter");
    }
    ui->label_hunter->setPixmap(pixmap_hunter.scaled(ui->label_hunter->width(), ui->label_hunter->height(), Qt::KeepAspectRatio));
    // initalize the goblin1 in mainwindow first time
    goblin goblin1;
    QPixmap pixmap_goblin1 = goblin1.get_goblin_image();
    if(pixmap_goblin1.isNull()){
        qDebug("failed to load");
    }
    ui->label_goblin->setPixmap(pixmap_goblin1.scaled(ui->label_goblin->width(), ui->label_goblin->height(), Qt::KeepAspectRatioByExpanding));

}

void MainWindow::mousePressEvent(QMouseEvent *event, int &x, int &y){
    if(event->button() == Qt::LeftButton){
        x = event->x();
        y = event->y();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    int x = ui->label_hunter->x();
    int y = ui->label_hunter->y();
    if(event->key() == Qt::Key_A){
        if(x-5 >= 0){
            ui->label_hunter->move(x - 5, y);
        }
    }else if(event->key() == Qt::Key_D){
        if(x+5 + ui->label_hunter->width() <= this->width()){
            ui->label_hunter->move(x + 5, y);
        }
    }else if(event->key() == Qt::Key_W) {
        if(y - 10 >= 0) {
            ui->label_hunter->move(x, y - 10);
        }
    }else if(event->key() == Qt::Key_S) {
        if(y + 10 + ui->label_hunter->height() <= this->height()) {
            ui->label_hunter->move(x, y + 10);
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
