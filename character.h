#ifndef CHARACTER_H
#define CHARACTER_H

#include <QLabel>

class character:public QLabel{
public:
    character();
    character(double, double, double);
    character(QWidget *parent, double, double, double);
    character(double, double, double, int, int);
    ~character();
    void attacked(character &targrt);
    bool isAlive();
    void increase_attack(int);
    void increase_defense(int);
    void heal(int);
    double getX()const;
    double getY()const;
    double getDef()const;
    double getAtk()const;
    double getHp()const;
    void changeHp(double);
protected:

private:
    double hp;
    double atk;
    double def;
    bool alive;
    int x;
    int y;
};

#endif // CHARACTER_H
