#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <qlabel.h>

class bullet:public QLabel{
public:
    bullet(int, int, QWidget*);
    ~bullet();
    QPixmap get_bulletImage()const;
    void increaseAtk();
    void increaseSize();
    void increasespeed();
    void show();
    int getX();
    int getY();
    // image size
    static int sizeWidth;
    static int sizeHeight;
    // bullet speed
    static int speed;
private:
    QPixmap bulletImage;
    static int atk;
    // postion (x,y)
    int x;
    int y;
};

#endif // BULLET_H
