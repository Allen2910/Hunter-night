#include <bullet.h>
#include <bits/stdc++.h>
#include <mainwindow.h>

bullet::bullet(int x, int y)
    :bulletImage(":/images/4.jpg"), x(x), y(y){
}
int bullet::atk = 10;
int bullet::size = 5;


QPixmap bullet::get_bulletImage()const{
    return bulletImage;
}

void bullet::increaseAtk(){
    atk += 5;
}

void bullet::increaseSize(){
    size += 5;
}

