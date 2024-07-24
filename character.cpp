#include <character.h>

character::character():hp(0), atk(0), def(0), alive(true){

}

character::character(double hp, double atk, double def)
    :hp(hp), atk(atk), def(def), alive(true){

}
