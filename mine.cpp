#include "mine.h"
#include "ui_mine.h"

mine::mine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mine)
{
    ui->setupUi(this);
}

mine::~mine()
{
    delete ui;
}
