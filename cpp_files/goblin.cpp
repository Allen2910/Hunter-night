#include <bits/stdc++.h>
#include <mainwindow.h>
#include <goblin.h>
#include <qpixmap.h>
#include <QDebug>
#include <main_character.h>
#include <qtimer.h>
#include <qboxlayout.h>
#include <QProgressBar>


goblin::goblin(QWidget *parent)
    :goblin_image(":/images/15.jpg"), character(parent,100,10,5), speed(10){
    if(goblin_image.isNull()){
        qDebug("Failed to load goblin image1");
    }
    setPixmap(goblin_image.scaled(250, 250, Qt::KeepAspectRatio));
}

goblin::goblin(QWidget *parent, int x, int y)
    :goblin_image(":/images/15.jpg"), character(parent,100,10,5), speed(10){
    if(goblin_image.isNull()){
        qDebug("Failed to load goblin image1");
    }
    QVBoxLayout *layout = new QVBoxLayout(this);


    // init image
    setGeometry(x, y, 250, 250);
    setPixmap(goblin_image.scaled(200, 200, Qt::KeepAspectRatioByExpanding));


    // init progress bar value
    progressBar = new QProgressBar(this);
    progressBar->setRange(0,this->getHp());
    progressBar->setValue(this->getHp());

    // init progress bar pos and size
    progressBar->setFixedHeight(8);
    progressBar->setStyleSheet("QProgressBar::chunk { background-color: red; }"
                               "QProgressBar { border: 1px solid #CCCCCC; border-radius: 5px; }");
    progressBar->setAlignment(Qt::AlignCenter);

    layout->addWidget(this);
    layout->addWidget(progressBar);
    layout->setAlignment(this, Qt::AlignTop);
    layout->setAlignment(progressBar, Qt::AlignBottom);

    //parent->setLayout(layout);
}

void goblin::updateProgressBar(){
    progressBar->setValue(this->getHp());
}

void goblin::getDamage(int atkPoint){
    qDebug() << this->getHp() << '\n' << atkPoint << '\n';
    this->changeHp(atkPoint);
    this->updateProgressBar();
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
