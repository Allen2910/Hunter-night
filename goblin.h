#ifndef GOBLIN_H
#define GOBLIN_H

#include <QImage>
#include <character.h>
#include <qicon.h>

class goblin:public character{
public:
    goblin();
    goblin(int, int);
    QPixmap get_goblin_image()const;
private:
    QPixmap goblin_image1;
};
#endif // GOBLIN_H
