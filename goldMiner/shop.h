 #ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <level.h>
#include <QPixmap>
#include <QSoundEffect>

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
    int numProp,num[3];
    Level * level;
    void buyProp(int id);
    void modifyButton();
    QSoundEffect *shop_bgm;

private slots:
    void on_nextLevelButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Shop *ui;
    int levelNum;

    QPixmap propmixmap;
    QPixmap prop_1mixmap;
    QPixmap prop_2mixmap;
    QPixmap prop_3mixmap;
};

#endif // SHOP_H
