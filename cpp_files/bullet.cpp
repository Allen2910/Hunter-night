#include <bullet.h>
#include <bits/stdc++.h>
#include <mainwindow.h>

bullet::bullet(int x, int y, QWidget* parent = nullptr)
    : QLabel(parent), bulletImage(":/images/4.jpg"), x(x), y(y){
    setGeometry(x, y, this->sizeWidth, this->sizeHeight);
    setPixmap(bulletImage.scaled(sizeWidth, sizeHeight, Qt::KeepAspectRatioByExpanding));
}
int bullet::atk = 10;
int bullet::sizeHeight = 200;
int bullet::sizeWidth = 200;
int bullet::speed = 40;

QPixmap bullet::get_bulletImage()const{
    return bulletImage;
}

void bullet::increaseAtk(){
    atk += 5;
}

void bullet::increaseSize(){
    sizeHeight *= 2;
    sizeWidth *= 2;
}

void bullet::increasespeed(){
    speed *= 2;
}

int bullet::getAtk()const{
    return atk;
}

bullet::~bullet(){

}

int bullet::getX(){
    return x;
}
int bullet::getY(){
    return y;
}

