#include <bits/stdc++.h>
#include <mainwindow.h>
#include <goblin.h>
#include <qpixmap.h>
#include <QDebug>

goblin::goblin()
    :goblin_image1(":/images/15.jpg"), character(30,10,5){
    if(goblin_image1.isNull()){
        qDebug("Failed to load goblin image1");
    }
}

goblin::goblin(int x, int y)
    :goblin_image1(":/images/15.jpg"), character(30,10,5){
    if(goblin_image1.isNull()){
        qDebug("Failed to load goblin image1");
    }
}


QPixmap goblin::get_goblin_image()const{
    return goblin_image1;
}
