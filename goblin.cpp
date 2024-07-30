#include <bits/stdc++.h>
#include <mainwindow.h>
#include <goblin.h>
#include <qpixmap.h>
#include <QDebug>
#include <main_character.h>
#include <qtimer.h>


goblin::goblin(QWidget *parent)
    :goblin_image(":/images/15.jpg"), character(parent,30,10,5), speed(10){
    if(goblin_image.isNull()){
        qDebug("Failed to load goblin image1");
    }
    setPixmap(goblin_image.scaled(200, 200, Qt::KeepAspectRatioByExpanding));
}

goblin::goblin(QWidget *parent, int x, int y)
    :goblin_image(":/images/15.jpg"), character(parent,30,10,5), speed(10){
    if(goblin_image.isNull()){
        qDebug("Failed to load goblin image1");
    }
    setGeometry(x, y, 200, 200);
    setPixmap(goblin_image.scaled(200, 200, Qt::KeepAspectRatioByExpanding));
}

void goblin::getDamage(int atkPoint){
    this->changeHp(atkPoint);
}

QPixmap goblin::get_goblin_image()const{
    return goblin_image;
}

int goblin::getSpeed()const{
    return speed;
}

void goblin::getAttackedPoint(int damage){
    int temp =  damage-this->getDef() <= 0 ? damage-this->getDef() : 0;
    this->getDamage(temp);
}
