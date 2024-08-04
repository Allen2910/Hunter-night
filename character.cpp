#include <character.h>

#define increase_unit_value 10


character::character(QWidget *parent, double hp = 0, double atk = 0, double def = 0)
    :QWidget(parent), hp(hp), atk(atk), def(def), alive(true){
    initCharacter();
}


character::character(QWidget *parent, double hp = 0, double atk = 0, double def = 0, double x = 0, double y = 0)
    :QWidget(parent), hp(hp), atk(atk), def(def), alive(true), x(x), y(y){
    initCharacter();
}

void character::initCharacter(){
    // init imageLabel
    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);

    // init progressBar
    hpProgressBar = new QProgressBar(this);
    hpProgressBar->setRange(0, hp);
    hpProgressBar->setValue(hp);
    hpProgressBar->setFixedHeight(10);
    hpProgressBar->setStyleSheet("QProgressBar::chunk { background-color: red; }"
                               "QProgressBar { border: 1px solid #CCCCCC; border-radius: 5px; }"
                               "QProgressBar { background-color: black; border: 1px solid black; }");
    hpProgressBar->setAlignment(Qt::AlignCenter);

    // init layout
    layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    layout->addWidget(hpProgressBar);
    setLayout(layout);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        if(this != nullptr){
            reloadhpProgressBar();
        }else{
            timer->stop();
        }
    });
    connect(this, &QObject::destroyed, timer, &QTimer::stop);
    timer->start(8);

}

void character::attacked(character &target){
    target.hp -= (this->atk)-(target.def);
    if(target.hp < 0){
        target.alive = false;
    }
}

double character::getX()const{
    return this->pos().x();
}

double character::getY()const{
    return this->pos().y();
}

bool character::isAlive(){
    return this->alive;
}

void character::increase_attack(int value = increase_unit_value){
    this->atk += value;
}

void character::increase_defense(int value = increase_unit_value){
    this->def += value;
}

void character::heal(int value = increase_unit_value){
    this->hp += value;
}

double character::getAtk()const{
    return this->atk;
}

double character::getDef()const{
    return this->def;
}

double character::getHp()const{
    return this->hp;
}

void character::changeHp(double changePoint = 0){
    this->hp += changePoint;
    if(this->hp <= 0) alive = false;
}

void character::reloadhpProgressBar(){
    this->hpProgressBar->setValue(this->hp);
}

character::~character(){

}
