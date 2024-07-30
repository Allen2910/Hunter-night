#include <main_character.h>
#include <qpixmap.h>

main_character::main_character(QWidget *parent)
    :character(parent,100,50,20), main_character_image(":/images/1.jpg"),
    speedX(10), speedY(10){
    setGeometry(100, 100, 200, 200);
    setPixmap(main_character_image.scaled(200, 200, Qt::KeepAspectRatio));
}

QPixmap main_character::get_main_character_image()const{
    return main_character_image;
}

main_character::~main_character(){

}

double main_character::getSpeedX()const{
    return speedX;
}

double main_character::getSpeedY()const{
    return speedY;
}

