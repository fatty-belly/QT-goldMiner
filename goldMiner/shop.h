#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <level.h>

namespace Ui {
class Shop;
}

class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(int coin_, QWidget *parent = nullptr, int levelNum_ = 1);
    ~Shop();
    static int coin;
    int numProp,num1,num2,num3;
    Level * level;

private slots:
    void on_nextLevelButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Shop *ui;
    int levelNum;
};

#endif // SHOP_H
