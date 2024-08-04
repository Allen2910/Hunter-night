#ifndef INITALSCREEN_H
#define INITALSCREEN_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class initalScreen;
}

class initalScreen : public QDialog
{
    Q_OBJECT

public:
    explicit initalScreen(QWidget *parent = nullptr);
    ~initalScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::initalScreen *ui;
    MainWindow *mainWindow;
};

#endif // INITALSCREEN_H
