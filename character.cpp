#include <character.h>

#define increase_unit_value 10
character::character():hp(0), atk(0), def(0), alive(true){

}

character::character(double hp, double atk, double def)
    :hp(hp), atk(atk), def(def), alive(true){

}

void character::attacked(character &target){
    target.hp -= (this->atk)-(target.def);
    if(target.hp < 0){
        target.alive = false;
    }
}

bool character::dead_or_not(){
    if(this->alive == false && this->hp < 0){
        return true;
    }
    return false;
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

character::~character(){

}
