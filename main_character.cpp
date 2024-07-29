#include <main_character.h>
#include <qpixmap.h>

main_character::main_character()
    :character(100,50,20), main_character_image(":/images/1.jpg"){

}

QPixmap main_character::get_main_character_image()const{
    return main_character_image;
}

main_character::~main_character(){

}


