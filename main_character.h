#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <bits/stdc++.h>
#include <qdebug.h>
#include <character.h>
#include <QPixmap>

class main_character:public character{
public:
    main_character();
    ~main_character();
    QPixmap get_main_character_image() const;
private:
    QPixmap main_character_image;
};

#endif // MAIN_CHARACTER_H
