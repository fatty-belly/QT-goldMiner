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
    QString daveSpeak[4] = {"/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak1.wav",
                              "/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak5.wav",
                              "/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak2.wav",
                              "/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak5.wav"};
    Level * level;
    void buyProp(int id);
    void setDaveText(int num);
    void modifyButton();
    void start();
    QSoundEffect *shop_bgm_player;
    QSoundEffect *Dave_player;



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
    QPixmap Davemixmap;
    void updateTimer();
    int elaspedTime = 0;
};

#endif // SHOP_H
