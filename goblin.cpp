#include <bits/stdc++.h>
#include <mainwindow.h>
#include <goblin.h>
#include <qpixmap.h>
#include <QDebug>

goblin::goblin()
    :goblin_image1(":/pictures/1.jpg"){
    if(goblin_image1.isNull()){
        qDebug("Failed to load goblin image1");
    }
}

goblin::goblin(int x, int y)
    :goblin_image1(":/pictures/1.jpg"){
    if(goblin_image1.isNull()){
        qDebug("Failed to load goblin image1");
    }
    goblin_image1.scaled(100,100,Qt::KeepAspectRatio);
}


QPixmap goblin::get_goblin_image()const{
    return goblin_image1;
}
