#ifndef CHARACTER_H
#define CHARACTER_H


class character{
public:
    friend class goblin;
    friend class main_character;
    character();
    character(double, double, double);
    character(double, double, double, int, int);
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
    int x;
    int y;
};

#endif // CHARACTER_H
