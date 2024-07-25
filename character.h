#ifndef CHARACTER_H
#define CHARACTER_H

class character{
public:
    character();
    character(double, double, double);
    ~character();
    void attacked(character &targrt);
    bool dead_or_not();
    void increase_attack(int);
    void increase_defense(int);
    void heal(int);
private:
    double hp;
    double atk;
    double def;
    bool alive;
};

#endif // CHARACTER_H
