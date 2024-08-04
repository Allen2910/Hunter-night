#include <main_character.h>
#include <qpixmap.h>
#include <QVBoxLayout>
#include <QProgressBar>

void main_character::initCharacter(){
    // character::initCharacter();

    main_character_image.load(":/images/1.jpg");
    if(main_character_image.isNull()){
        qDebug("Failed to load main character image");
    }else{
        qDebug() << "Image size:" << main_character_image.size();
    }

    setFixedSize(150, 150+30);  // 250 for image, 30 for progressbar
    imageLabel->setPixmap(main_character_image.scaled(250, 250, Qt::KeepAspectRatioByExpanding));
}

main_character::main_character(QWidget *parent)
    :character(parent,100,20,10), speed(10){

    initCharacter();
}

QPixmap main_character::get_main_character_image()const{
    return main_character_image;
}

main_character::~main_character(){

}

double main_character::getSpeed()const{
    return speed;
}


void main_character::getDamage(int atkPoint){
    qDebug() << "main character:: hp:" << this->getHp() << "  get atkPoint:" << atkPoint << '\n';
    this->changeHp(atkPoint);
}

void main_character::getAttackedPoint(int damage){
    int temp =  damage-this->getDef() >= 0 ? damage-this->getDef() : 0;
    this->getDamage(-temp);
}

