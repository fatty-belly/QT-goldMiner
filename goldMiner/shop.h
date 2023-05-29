#ifndef SHOP_H
#define SHOP_H

#include <QWidget>

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
    const int prop_num;
    int num1,num2,num3;

private slots:
    void on_nextLevelButton_clicked();

private:
    Ui::Shop *ui;
    int levelNum;
};

#endif // SHOP_H
