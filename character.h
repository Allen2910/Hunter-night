#ifndef CHARACTER_H
#define CHARACTER_H

class character{
public:
    character();
    character(double, double, double);
private:
    double hp;
    double atk;
    double def;
    bool alive;
};

#endif // CHARACTER_H
