#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>

class bullet{
public:
    bullet(int ,int);
    ~bullet();
    QPixmap get_bulletImage()const;
    void increaseAtk();
    void increaseSize();
private:
    QPixmap bulletImage;
    static int atk;
    static int size;
    int x,y;
};

#endif // BULLET_H
