#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "goblin.h"
#include "main_character.h"
#include <QPixmap>
#include <QMessageBox>
#include <QMouseEvent>
#include <QKeyEvent>
#include <bits/stdc++.h>
#include <QtCore>
#include <QTimer>
#include <QObject>

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


int MainWindow::getHunterX()const{
    return ui->label_hunter->x();
}

int MainWindow::getHunterY()const{
    return ui->label_hunter->y();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int mouseX, mouseY;
    if(event->button() == Qt::LeftButton){
        mouseX = event->pos().x();
        mouseY = event->pos().y();

        qDebug() << "WTF\n";

        bullet *label_bullet = new bullet(getHunterX(), getHunterY(), this);
        label_bullet->QLabel::show();

        double deltaX = (mouseX - getHunterX());
        double deltaY = (mouseY - getHunterY());
        double unitSpeedX = deltaX/sqrt((deltaX*deltaX)+(deltaY*deltaY));
        double unitSpeedY = deltaY/sqrt((deltaX*deltaX)+(deltaY*deltaY));

        qDebug("%lf %lf\n", unitSpeedX, unitSpeedY);

        QPointer<QTimer> timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [this, label_bullet, unitSpeedX, unitSpeedY]() {
            if (label_bullet) {
                bulletShooting(label_bullet, unitSpeedX, unitSpeedY);
            }
        });
        connect(label_bullet, &QObject::destroyed, timer, &QTimer::stop);
        timer->start(50);

    }
}


void MainWindow::bulletShooting(bullet *label_bullet, double unitSpeedX, double unitSpeedY) {
    if(!label_bullet) return;

    int newX = label_bullet->pos().x() + unitSpeedX*label_bullet->speed;
    int newY = label_bullet->pos().y() + label_bullet->speed*unitSpeedY;

    if (newX < 0 || newX > width() || newY < 0 || newY > height()) {
        label_bullet->clear();
        label_bullet->deleteLater();  // delete bullet
        return;
    }

    label_bullet->move(newX, newY);

    // if bullet hit the monster => monster drop the exp and bullet disappear
    // if the bullet out of the range also dissppear

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
