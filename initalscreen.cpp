#include "initalscreen.h"
#include "ui_initalscreen.h"

initalScreen::initalScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::initalScreen)
{
    ui->setupUi(this);
}

initalScreen::~initalScreen()
{
    delete ui;
}

void initalScreen::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow();
    mainWindow->show();
}

