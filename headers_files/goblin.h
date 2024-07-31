#ifndef GOBLIN_H
#define GOBLIN_H

#include <character.h>
#include <main_character.h>
#include <QPixmap>
#include <qwidget.h>
#include <QLabel>
#include <qprogressbar.h>


class goblin:public character{
public:
    goblin(QWidget*);
    goblin(QWidget*, int, int);
    QPixmap get_goblin_image()const;
    int getSpeed()const;
    void getAttackedPoint(int);
    void updateProgressBar();
private:
    void getDamage(int);
    QPixmap goblin_image;
    QProgressBar *progressBar;
    int speed;
};
#endif // GOBLIN_H

