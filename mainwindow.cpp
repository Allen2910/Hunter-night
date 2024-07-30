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
    hunter->show();

    // upgrade the hunter pos
    QTimer *hunterTimer = new QTimer(this);
    connect(hunterTimer, &QTimer::timeout, this, &MainWindow::upgradePostion);
    hunterTimer->start(8);

    // initalize the goblin1 in mainwindow first time
    for(int i = 0; i < 10; i++){
        goblin *label_goblin = new goblin(this,QRandomGenerator::global()->bounded(0,500), QRandomGenerator::global()->bounded(0,500));
        goblinList.insert(label_goblin);
        label_goblin->show();
        chase(label_goblin);
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    int mouseX, mouseY;
    if(event->button() == Qt::LeftButton){
        mouseX = event->pos().x();
        mouseY = event->pos().y();

        qDebug() << "WTF\n";

        bullet *label_bullet = new bullet(hunter->getX(), hunter->getY(), this);
        label_bullet->QLabel::show();

        double deltaX = (mouseX - hunter->getX());
        double deltaY = (mouseY - hunter->getY());
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
        timer->start(40);

    }
}



void MainWindow::bulletShooting(bullet *label_bullet, double unitSpeedX, double unitSpeedY) {
    if(!label_bullet) return;

    int newX = label_bullet->pos().x() + unitSpeedX*label_bullet->speed;
    int newY = label_bullet->pos().y() + label_bullet->speed*unitSpeedY;

    // if the bullet out of the range also dissppear
    if (newX < 0 || newX > width() || newY < 0 || newY > height()) {
        label_bullet->clear();
        label_bullet->deleteLater();  // delete bullet
        return;
    }

    // show the bullet pos
    label_bullet->move(newX, newY);

    // if bullet hit the monster => monster drop the exp and bullet disappear
    for(goblin *monster: goblinList){
        if(isCollision(label_bullet, monster)){
            // monster hit by bullet and get damage
            monster->getAttackedPoint(label_bullet->getAtk());

            // bullet disappear cause hit the monster
            label_bullet->clear();
            label_bullet->deleteLater();

            // if the monter dead or not
            if(monster->isAlive() <= 0){
                goblinList.remove(monster);
                monster->clear();
                monster->deleteLater();
            }

            break;
        }
    }

}

template<class T>
bool MainWindow::isCollision(bullet *label_bullet, T *monster){
    QRect bulletRect = label_bullet->geometry();
    QRect monsterRect = monster->geometry();
    return bulletRect.intersects(monsterRect);
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    keysPressed.insert(event->key());
    QWidget::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    keysPressed.remove(event->key());
    QWidget::keyReleaseEvent(event);
}

void MainWindow::upgradePostion(){
    int newX = hunter->getX();
    int newY = hunter->getY();
    if (keysPressed.contains(Qt::Key_W) && newY-hunter->getSpeedY() > 0) newY -= hunter->getSpeedY(); // 上
    if (keysPressed.contains(Qt::Key_S) && newY+hunter->getSpeedY() < this->height()) newY += hunter->getSpeedY(); // 下
    if (keysPressed.contains(Qt::Key_A) && newX-hunter->getSpeedX() > 0) newX -= hunter->getSpeedX(); // 左
    if (keysPressed.contains(Qt::Key_D) && newX+hunter->getSpeedX() < this->width()) newX += hunter->getSpeedX(); // 右

    hunter->move(newX, newY);

}


template<class T>
void MainWindow::chase(T *monster){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        if (monster != nullptr) {
            double deltaX = hunter->getX() - monster->getX();
            double deltaY = hunter->getY() - monster->getY();
            double unitSpeedX = deltaX/sqrt((deltaX*deltaX)+(deltaY*deltaY));
            double unitSpeedY = deltaY/sqrt((deltaX*deltaX)+(deltaY*deltaY));
            chasing(monster, unitSpeedX, unitSpeedY);
        }
    });
    connect(monster, &QObject::destroyed, timer, &QTimer::stop);
    timer->start(100);
}

template<class T>
void MainWindow::chasing(T *monster, double unitSpeedX, double unitSpeedY){
    if(monster == nullptr) return;

    int newX = monster->getX() + unitSpeedX*monster->getSpeed();
    int newY = monster->getY() + monster->getSpeed()*unitSpeedY;

    if(newX < 0 || newX > this->width() || newY < 0 || newY > this->height()) {
        monster->clear();
        monster->deleteLater();
        return;
    }else{
        monster->move(newX, newY);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
