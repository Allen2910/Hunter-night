#include <bits/stdc++.h>
#include <mainwindow.h>
#include <goblin.h>
#include <qpixmap.h>
#include <QDebug>
#include <main_character.h>
#include <qtimer.h>
#include <qboxlayout.h>
#include <QProgressBar>


void goblin::initCharacter(){
    // character::initCharacter();

    goblin_image.load(":/images/15.jpg");
    if(goblin_image.isNull()){
        qDebug("Failed to load goblin image");
    }else{
        qDebug() << "Image size:" << goblin_image.size();
    }

    setFixedSize(150, (150)+30);  // 250 for image, 30 for progressbar
    imageLabel->setPixmap(goblin_image.scaled(250, 250, Qt::KeepAspectRatio));
}

goblin::goblin(QWidget *parent)
    :character(parent,100,20,10), speed(10){

    initCharacter();

}

goblin::goblin(QWidget *parent, int x, int y)
    : character(parent,100,20,10), speed(10){

    initCharacter();
    move(x,y);

}



void goblin::getDamage(int atkPoint){
    // qDebug() << this->getHp() << '\n' << atkPoint << '\n';
    this->changeHp(atkPoint);
}

QPixmap goblin::get_goblin_image()const{
    return goblin_image;
}

int goblin::getSpeed()const{
    return speed;
}

void goblin::getAttackedPoint(int damage){
    int temp =  damage-this->getDef() >= 0 ? damage-this->getDef() : 0;
    this->getDamage(-temp);
}
/*
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        if(this != nullptr){
            progressBar->setGeometry(0, this->height(), progressBar->width(), progressBar->height());
            progressBar->raise();
        }
        // debugging test
        qDebug("goblin::x:%lf y:%lf", this->getX(), this->getY());
        qDebug("progressbar::x:%d y:%d width:%d height:%d",
               progressBar->x(), progressBar->y(), progressBar->width(), progressBar->height());
        qDebug("goblin::x:%lf y:%lf\n", this->getX(), this->getY());
        qDebug("progressbar::x:%lf y:%lf\n", progressBar->pos().x(), progressBar->pos().y());
    });
    timer->start(20);
*/
