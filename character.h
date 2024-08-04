#ifndef CHARACTER_H
#define CHARACTER_H

#include <QLabel>
#include <QWidget>
#include <QProgressBar>
#include <QLayout>
#include <QTimer>

class character:public QWidget{
public:
    character(QWidget *, double, double, double);
    character(QWidget *, double, double, double, double, double);
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
    QLabel *imageLabel;
    QProgressBar *hpProgressBar;
    virtual void initCharacter();

private:
    double hp;
    double atk;
    double def;
    bool alive;
    double x;
    double y;
    int fps;
    QVBoxLayout *layout;

    void reloadhpProgressBar();
};

#endif // CHARACTER_H
