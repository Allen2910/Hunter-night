#ifndef GOBLIN_H
#define GOBLIN_H

#include <character.h>
#include <main_character.h>
#include <QPixmap>
#include <qwidget.h>
#include <QLabel>
#include <qprogressbar.h>
#include <qmutex.h>


class goblin:public character{
public:
    goblin(QWidget*);
    goblin(QWidget*, int, int);
    QPixmap get_goblin_image()const;
    int getSpeed()const;
    void getAttackedPoint(int);
    void updateProgressBar();
    // minisec
    int fps;
protected:
    void initCharacter()override;
private:
    void getDamage(int);
    QPixmap goblin_image;
    int speed;
    mutable QMutex mutex;
};
#endif // GOBLIN_H

