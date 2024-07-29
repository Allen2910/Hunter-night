#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <main_character.h>
#include <bullet.h>

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
    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);
    int getHunterX()const;
    int getHunterY()const;
public slots:
    void bulletShooting(bullet*, double, double);
private:
    Ui::MainWindow *ui;
    // initalize the hunter in mainwindow first time
    main_character hunter;

};
#endif // MAINWINDOW_H
