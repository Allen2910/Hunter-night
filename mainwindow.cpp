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
#include <QTime>
#include <qpushbutton.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    // QPushButton *startButton = new QPushButton("&Start", this);


    // put the hunter image on mainwindow
    hunter->show();

    // upgrade the hunter pos
    QTimer *hunterTimer = new QTimer(this);
    connect(hunterTimer, &QTimer::timeout, this, &MainWindow::upgradePostion);
    hunterTimer->start(8);


    // initalize the goblin1 in mainwindow first time
    /*
     * note: how to design the monster appear in the dialog
     */
    /*
    for(int i = 0; i < 1; i++){
        goblin *label_goblin = new goblin(this,QRandomGenerator::global()->bounded(0,500), QRandomGenerator::global()->bounded(0,500));
        goblinList.insert(label_goblin);
        label_goblin->show();
        chaseBy(label_goblin);
    }
    AttackedByGoblin();
    */


    // mini sec
    int frequency = 5000;
    int amount = 3;
    QTimer *goblinTimer = new QTimer(this);
    connect(goblinTimer, &QTimer::timeout, [this, frequency, amount]()mutable{
        if(frequency > 200){
            frequency /= 2;
        }
        int random = QRandomGenerator::global()->bounded(0,500);
        int x, y;
        if(random % 2 == 0){
            if(random < 250){
                x = 1;
            }else{
                x = this->width()-1;
            }
            y = QRandomGenerator::global()->bounded(0,this->height());
        }else{
            if(random < 250){
                y = 1;
            }else{
                y = this->height()-1;
            }
            x = QRandomGenerator::global()->bounded(0,this->width());
        }
        for(int i = 0; i < amount; i++){
            goblin *label_goblin = new goblin(this,QRandomGenerator::global()->bounded(0,500), QRandomGenerator::global()->bounded(0,500));
            goblinList.insert(label_goblin);
            label_goblin->show();
            chaseBy(label_goblin);
        }
    });
    goblinTimer->start(frequency);
    AttackedByGoblin();



}



void MainWindow::AttackedByGoblin(){
    int interval = 500;

    QPointer<QTimer> timer = new QTimer(this);
    // timer->setInterval(interval);
    // how long to reload the pos

    connect(timer, &QTimer::timeout, [=]() mutable {
        if (hunter != nullptr) {
            for(goblin *monster: goblinList){
                if(isCollision(monster)){
                    qDebug() << "hunter get attacked";
                    // hunter get attacked by monster and get damage
                    hunter->getAttackedPoint(monster->getAtk());

                    // if the hunter dead or not
                    if(!hunter->isAlive()){
                        hunter->deleteLater();

                        QMessageBox::information(this, "Game Over", "The hunter has died. Game over.");
                        QApplication::quit();
                        return;
                    }else{
                        repel(monster);
                    }

                    break;
                }
            }
        }
    });
    timer->start(interval);

}


void MainWindow::mousePressEvent(QMouseEvent *event){
    int mouseX, mouseY;
    if(event->button() == Qt::LeftButton){
        mouseX = event->pos().x();
        mouseY = event->pos().y();


        bullet *label_bullet = new bullet(hunter->getX(), hunter->getY(), this);
        label_bullet->QLabel::show();

        double deltaX = (mouseX - hunter->getX());
        double deltaY = (mouseY - hunter->getY());
        double unitSpeedX = deltaX/sqrt((deltaX*deltaX)+(deltaY*deltaY));
        double unitSpeedY = deltaY/sqrt((deltaX*deltaX)+(deltaY*deltaY));

        // qDebug("LeftMouse unitSpeedX:%lf  unitSpeedY%lf\n", unitSpeedX, unitSpeedY);

        QPointer<QTimer> timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [this, label_bullet, unitSpeedX, unitSpeedY]() {
            if (label_bullet != nullptr) {
                bulletShooting(label_bullet, unitSpeedX, unitSpeedY);
            }
        });
        connect(label_bullet, &QObject::destroyed, timer, &QTimer::stop);
        timer->start(40);

    }
}


template<class T>
void MainWindow::repel(T *object, double unitSpeedX, double unitSpeedY) {
    // duration time
    const int duration = 500;
    const int interval = 5;


    double deltaX = (unitSpeedX * interval / 1000.0)*5;
    double deltaY = (unitSpeedY * interval / 1000.0)*5;

    QPointer<QTimer> timer = new QTimer(this);

    QTime startTime = QTime::currentTime();
    connect(timer, &QTimer::timeout, [=]() mutable {
        if (object != nullptr) {
            int elapsed = startTime.msecsTo(QTime::currentTime());
            if (elapsed > duration) {
                timer->stop();
                return;
            }

            double newX = object->getX()+deltaX;
            double newY = object->getY()+deltaY;
            if(newX > 0 && newX < this->width()) object->move(newX, object->getY());
            if(newY > 0 && newY < this->height()) object->move(object->getX(), newY);
        }
    });
    connect(object, &QObject::destroyed, timer, &QTimer::stop);
    timer->start(interval);
}

template<class T>
void MainWindow::repel(QSharedPointer<T> object, double unitSpeedX, double unitSpeedY) {
    // duration time
    const int duration = 500;
    const int interval = 5;


    double deltaX = (unitSpeedX * interval / 1000.0)*5;
    double deltaY = (unitSpeedY * interval / 1000.0)*5;

    QPointer<QTimer> timer = new QTimer(this);
    timer->setInterval(interval);
    // how long to reload the pos

    QTime startTime = QTime::currentTime();
    connect(timer, &QTimer::timeout, [=]() mutable {
        if (object != nullptr) {
            int elapsed = startTime.msecsTo(QTime::currentTime());
            if (elapsed > duration) {
                timer->stop();
                return;
            }

            double newX = object->getX()+deltaX;
            double newY = object->getY()+deltaY;
            if(newX > 0 && newX < this->width()) object->move(newX, object->getY());
            if(newY > 0 && newY < this->height()) object->move(object->getX(), newY);
        }
    });
    timer->start();
}



template<class T>
void MainWindow::repel(T *object){
    // duration time
    const int duration = 500;
    const int interval = 5;


    double deltax = hunter->getX()-object->getX();
    double deltay = hunter->getY()-object->getY();
    double distance = (deltax*deltax)+(deltay*deltay);
    if(distance == 0) return;

    double unitSpeedX = deltax/sqrt(distance);
    double unitSpeedY = deltay/sqrt(distance);

    double deltaX = (unitSpeedX * interval / 1000.0)*100;
    double deltaY = (unitSpeedY * interval / 1000.0)*100;

    QPointer<QTimer> timer = new QTimer(this);

    QTime startTime = QTime::currentTime();
    connect(timer, &QTimer::timeout, [=]() mutable {
        if (object != nullptr) {
            int elapsed = startTime.msecsTo(QTime::currentTime());
            if (elapsed > duration) {
                timer->stop();
                return;
            }

            double newX = object->getX()+deltaX;
            double newY = object->getY()+deltaY;
            if(newX > 0 && newX < this->width()) object->move(newX, object->getY());
            if(newY > 0 && newY < this->height()) object->move(object->getX(), newY);
        }
    });
    connect(object, &QObject::destroyed, timer, &QTimer::stop);
    timer->start(interval);
}



void MainWindow::repel(){
    /*
    // duration time
    const int duration = 500;
    const int interval = 4;


    double deltaX = (unitSpeedX * interval / 1000.0)*5;
    double deltaY = (unitSpeedY * interval / 1000.0)*5;

    QPointer<QTimer> timer = new QTimer(this);


    QTime startTime = QTime::currentTime();
    connect(timer, &QTimer::timeout, [=]() mutable {
        if (object != nullptr) {
            int elapsed = startTime.msecsTo(QTime::currentTime());
            if (elapsed > duration) {
                timer->stop();
                return;
            }

            int newX = object->getX()+deltaX;
            int newY = object->getY()+deltaY;
            if(newX > 0 && newX < this->width()) object->move(newX, object->getY());
            if(newY > 0 && newY < this->height()) object->move(object->getX(), newY);
        }
    });
    timer->start(interval);
    */
    return;
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
        if(monster == nullptr) continue;

        if(isCollision(label_bullet, monster)){
            // debugging test
            // qDebug("bullet hit the goblin\n");

            // monster hit by bullet and get damage
            // note: choose which is the atk:hunter or bullet?
            monster->getAttackedPoint(hunter->getAtk());

            // bullet disappear cause hit the monster
            label_bullet->clear();
            label_bullet->deleteLater();

            // debugging test
            // qDebug("goblin hp: %lf", monster->getHp());

            // if the monter dead or not
            if(!monster->isAlive()){
                goblinList.remove(monster);
                delete monster;
                monster = nullptr;
            }else{
                repel(monster, unitSpeedX, unitSpeedY);
            }

            break;
        }
    }

}

template<class T>
bool MainWindow::isCollision(bullet *label_bullet, QSharedPointer<T> monster){
    QRect bulletRect = label_bullet->geometry();
    QRect monsterRect = monster->geometry();
    return bulletRect.intersects(monsterRect);
}

template<class T>
bool MainWindow::isCollision(bullet *label_bullet, T *monster){
    QRect bulletRect = label_bullet->geometry();
    QRect monsterRect = monster->geometry();
    return bulletRect.intersects(monsterRect);
}

template<class T>
bool MainWindow::isCollision(T* monster){
    QRect hunterRect = hunter->geometry();
    QRect monsterRect = monster->geometry();
    return monsterRect.intersects(hunterRect);
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
    double newX = hunter->getX();
    double newY = hunter->getY();

    double centerX = newX+(hunter->width())/2;
    double centerY = newY+(hunter->height())/2;
    // note: i cancael the function
    if (keysPressed.contains(Qt::Key_W)){
        if(centerY-hunter->getSpeed() > 0) newY -= hunter->getSpeed();
        // else newY = this->height();
    }
    if (keysPressed.contains(Qt::Key_S)){
        if(centerY+hunter->getSpeed() < this->height()) newY += hunter->getSpeed();
        // else newY = 0;
    }
    if (keysPressed.contains(Qt::Key_A)){
        if(centerX-hunter->getSpeed() > 0) newX -= hunter->getSpeed();
        // else newX = this->width();
    }
    if (keysPressed.contains(Qt::Key_D)){
        if(centerX+hunter->getSpeed() < this->width()) newX += hunter->getSpeed();
        // else newX = 0;
    }

    // debugging test
    // qDebug("newX:%lf  newY:%lf\n", newX, newY);

    hunter->move(newX, newY);
}



template<class T>
void MainWindow::chaseBy(T *monster){
    QTimer *chasingtimer = new QTimer(this);
    connect(chasingtimer, &QTimer::timeout, [=]() {
        if (monster != nullptr) {
            double deltaX = hunter->getX() - monster->getX();
            double deltaY = hunter->getY() - monster->getY();

            double distance = sqrt((deltaX*deltaX)+(deltaY*deltaY));
            if(distance == 0){
                return;
            }

            double unitSpeedX = deltaX / distance;
            double unitSpeedY = deltaY / distance;

            // debuggint test
            // qDebug("unitSpeed:%lf   unitSpeedY:%lf\n", unitSpeedX, unitSpeedY);

            chasing(monster, unitSpeedX, unitSpeedY);
        }
    });
    connect(monster, &QObject::destroyed, chasingtimer, &QTimer::stop);
    chasingtimer->start(30);
}

template<class T>
void MainWindow::chasing(T *monster, double unitSpeedX, double unitSpeedY){
    if(monster == nullptr) return;

    double newX = monster->getX() + unitSpeedX*monster->getSpeed();
    double newY = monster->getY() + monster->getSpeed()*unitSpeedY;


    if(newX < 0 || newX > this->width()){
        newX = monster->getX();
    }
    if(newY < 0 || newY > this->height()){
        newY = monster->getY();
    }


    // note:there's almost no difference cause fps is quicker than that
    /*
    if(newX < 0){
        newX = this->width();
    }else if(newX > this->width()){
        newX = 0;
    }
    if(newY < 0){
        newY = this->height();
    }else if(newY > this->height()){
        newY = 0;
    }
    */

    monster->move(newX, newY);
    monster->update();
}



MainWindow::~MainWindow()
{
    delete ui;
}
