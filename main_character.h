#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <bits/stdc++.h>
#include <qdebug.h>
#include <character.h>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>


class main_character:public character{
public:
    main_character(QWidget *parent = nullptr);
    ~main_character();
    QPixmap get_main_character_image()const;
    double getSpeed()const;
    void getDamage(int);
    void getAttackedPoint(int);
protected:
    void initCharacter()override;
private:
    QPixmap main_character_image;
    double speed;
};

#endif // MAIN_CHARACTER_H
