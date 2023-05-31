#include "shop.h"
#include "hook.h"
#include "level.h"
#include "ui_shop.h"
#include <bomb.h>
#include <QRandomGenerator>


int Shop::coin=0;
Shop::Shop(int coin_,QWidget *parent,int levelNum_) :
    QWidget(parent),
    ui(new Ui::Shop),
    levelNum(levelNum_),
    propmixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/TNT.png"),
    prop_1mixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/+.png"),
    prop_2mixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/time.png"),
    prop_3mixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bag.png"),
    Davemixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/CrazyDave.png")
{
    coin += coin_;
    numProp = 4;
    ui->setupUi(this);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    level= new Level(nullptr, levelNum);

    // 播放BGM
    shop_bgm_player = new QSoundEffect(this);
    shop_bgm_player->setSource(QUrl::fromLocalFile("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/shop_bgm.wav"));
    shop_bgm_player->setLoopCount(QSoundEffect::Infinite);
    shop_bgm_player->setVolume(1);
    shop_bgm_player->play();

    Dave3_player = new QSoundEffect(this);
    Dave3_player->setSource(QUrl::fromLocalFile("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak3.wav"));
    Dave3_player->setLoopCount(1);
    Dave3_player->play();

    // 产生三个随机数
    int index = 0;
    while (true){
        int randomNum = QRandomGenerator::global()->bounded(0, numProp);
        if (index == 0){
            num[0] = randomNum;
        }
        else if(index == 1){
            if (randomNum != num[0]){
                num[1] = randomNum;
            }
            else{
                continue;
            }
        }
        else{
            if (randomNum != num[0] && num[1] != randomNum){
                num[2] = randomNum;
                break;
            }
            else{
                continue;
            }
        }
        index++;
    }
    // 生成UI图片和文字
    propmixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_1mixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_2mixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_3mixmap.scaled(20,20,Qt::KeepAspectRatio);

    ui->label_8->setPixmap(Davemixmap);
    QLabel* textLabel[3] = {ui->label,ui->label_2,ui->label_3};
    QLabel* pixLabel[3] = {ui->label_5,ui->label_6,ui->label_7};
    QPushButton* button[3] ={ui->pushButton,ui->pushButton_2,ui->pushButton_3};
    for(int i=0;i<3;i++)
    {
        switch (num[i]){
        case 0:// 炸药
            textLabel[i]->setText("炸药 $1000");
            pixLabel[i]->setPixmap(propmixmap);
            if(coin<1000)
                button[i]->setEnabled(false);
            break;
        case 1:// 大力药水
            textLabel[i]->setText("大力药水 $3500");
            pixLabel[i]->setPixmap(prop_1mixmap);
            if(coin<3500)
                button[i]->setEnabled(false);
            break;
        case 2:// 增加时间
            textLabel[i]->setText("增加15秒 $5000");
            pixLabel[i]->setPixmap(prop_2mixmap);
            if(coin<5000)
                button[i]->setEnabled(false);
            break;
        case 3:// 减半
            textLabel[i]->setText("时间减半 目标分数减半\n $8000");
            pixLabel[i]->setPixmap(prop_3mixmap);
            if(coin<8000)
                button[i]->setEnabled(false);
            break;
        default:
            break;
        }
    }
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_nextLevelButton_clicked()
{
    QTimer *gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, level, &Level::updateTimer);
    gameTimer->start(1000);
    shop_bgm_player->stop();
    level->show();
    level->player->play();
    this->hide();
}

void Shop::buyProp(int id)
{
    switch (id) {
    case 0:// 炸药
        if (coin >= 1000){
            coin -= 1000;
            Bomb::bombNum += 1;
        }
        break;
    case 1:// 增加钩子速度
        if (coin >= 3500){
            coin -= 3500;
            level->hook->multiplier *= 1.2;
        }
        break;
    case 2:// 增加时间
        if (coin >= 5000){
            coin -= 5000;
            level->restTime += 15;
        }
        break;
    case 3:// 减半
        if (coin >= 8000){
            coin -= 8000;
            level->restTime /= 2;
            level->goalScore /= 2;
            level->ui->goalScoreLabel->setText(QString("目标分数:%1").arg(level->goalScore));
        }
        break;
    default:
        break;
    }
}

void Shop::modifyButton()
{
    QPushButton* button[3] ={ui->pushButton,ui->pushButton_2,ui->pushButton_3};
    for(int i=0;i<3;i++)
    {
        switch (num[i]){
        case 0:// 炸药
            if(coin<1000)
                button[i]->setEnabled(false);
            break;
        case 1:// 大力药水
            if(coin<3500)
                button[i]->setEnabled(false);
            break;
        case 2:// 增加时间
            if(coin<5000)
                button[i]->setEnabled(false);
            break;
        case 3:// 减半
            if(coin<8000)
                button[i]->setEnabled(false);
            break;
        default:
            break;
        }
    }
}

void Shop::on_pushButton_clicked()
{
    Dave1_player = new QSoundEffect(this);
    Dave1_player->setSource(QUrl::fromLocalFile("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak1.wav"));
    Dave1_player->setLoopCount(1);
    Dave1_player->play();
    buyProp(num[0]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton->setEnabled(false);
    modifyButton();
}

void Shop::on_pushButton_2_clicked()
{
    Dave5_player = new QSoundEffect(this);
    Dave5_player->setSource(QUrl::fromLocalFile("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak5.wav"));
    Dave5_player->setLoopCount(1);
    Dave5_player->play();
    buyProp(num[1]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton_2->setEnabled(false);
    modifyButton();
}


void Shop::on_pushButton_3_clicked()
{
    Dave4_player = new QSoundEffect(this);
    Dave4_player->setSource(QUrl::fromLocalFile("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Music/DaveSpeak4.wav"));
    Dave4_player->setLoopCount(1);
    Dave4_player->play();
    buyProp(num[2]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton_3->setEnabled(false);
    modifyButton();
}


