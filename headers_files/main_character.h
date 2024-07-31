#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <bits/stdc++.h>
#include <qdebug.h>
#include <character.h>
#include <QPixmap>
#include <QLabel>

class main_character:public character{
public:
    main_character(QWidget *parent);
    ~main_character();
    QPixmap get_main_character_image()const;
    double getSpeedX()const;
    double getSpeedY()const;
private:
    QPixmap main_character_image;
    double speedX;
    double speedY;
};

#endif // MAIN_CHARACTER_H
