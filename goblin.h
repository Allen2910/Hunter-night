#ifndef GOBLIN_H
#define GOBLIN_H


#include <character.h>
#include <qpixmap.h>

class goblin:public character{
public:
    goblin();
    goblin(int, int);
    QPixmap get_goblin_image()const;
private:
    QPixmap goblin_image1;
};
#endif // GOBLIN_H
