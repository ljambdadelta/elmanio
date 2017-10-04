#ifndef MINE_H
#define MINE_H

#include <QMainWindow>

namespace Ui {
class mine;
}

class mine : public QMainWindow
{
    Q_OBJECT

public:
    explicit mine(QWidget *parent = 0);
    ~mine();

private:
    Ui::mine *ui;
};

#endif // MINE_H
