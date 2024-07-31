#include <character.h>

#define increase_unit_value 10

character::character()
    :hp(0), atk(0), def(0), alive(true), x(this->QLabel::x()), y(this->QLabel::y()){

}

character::character(double hp, double atk, double def)
    :hp(hp), atk(atk), def(def), alive(true), x(this->QLabel::x()), y(this->QLabel::y()){

}

character::character(QWidget *parent, double hp = 0, double atk = 0, double def = 0)
    :QLabel(parent), hp(hp), atk(atk), def(def), alive(true), x(this->QLabel::x()), y(this->QLabel::y()){

}

character::character(double hp, double atk, double def, int x, int y)
    :hp(hp), atk(atk), def(def), alive(true), x(x), y(y){

}

void character::attacked(character &target){
    target.hp -= (this->atk)-(target.def);
    if(target.hp < 0){
        target.alive = false;
    }
}

double character::getX()const{
    return this->QLabel::x();
}

double character::getY()const{
    return this->QLabel::y();
}

bool character::isAlive(){
    return this->alive;
}

void character::increase_attack(int value = increase_unit_value){
    this->atk += value;
}

void character::increase_defense(int value = increase_unit_value){
    this->def += value;
}

void character::heal(int value = increase_unit_value){
    this->hp += value;
}

double character::getAtk()const{
    return this->atk;
}

double character::getDef()const{
    return this->def;
}

double character::getHp()const{
    return this->hp;
}

void character::changeHp(double changePoint = 0){
    this->hp += changePoint;
    if(this->hp <= 0) alive = false;
}



character::~character(){

}
