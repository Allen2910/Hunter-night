#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <main_character.h>
#include <bullet.h>
#include <goblin.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class bullet;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent*)override;
    void keyPressEvent(QKeyEvent*)override;
    void keyReleaseEvent(QKeyEvent*)override;
    template<class T>
    void chase(T*);
    template<class T>
    void chasing(T*, double, double);
    template<class T>
    void bulletHitMonster(bullet*, T*);
public slots:
    void bulletShooting(bullet*, double, double);
    void upgradePostion();
protected:
    template<class T>
    bool isCollision(bullet*, T*);

private:
    Ui::MainWindow *ui;
    // initalize the hunter in mainwindow first time
    main_character *hunter = new main_character(this);
    QSet<int> keysPressed;
    QSet<goblin*> goblinList;

};
#endif // MAINWINDOW_H
