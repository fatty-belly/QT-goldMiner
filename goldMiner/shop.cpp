#include "shop.h"
#include "hook.h"
#include "level.h"
#include "ui_shop.h"
#include <bomb.h>
#include <QRandomGenerator>
#include <QThread>


int Shop::coin=0;
Shop::Shop(int coin_,QWidget *parent,int levelNum_) :
    QWidget(parent),
    ui(new Ui::Shop),
    levelNum(levelNum_),
    propmixmap("../goldMiner/Images/TNT.png"),
    prop_1mixmap("../goldMiner/Images/+.png"),
    prop_2mixmap("../goldMiner/Images/time.png"),
    prop_3mixmap("../goldMiner/Images/bag.png"),
    Davemixmap("../goldMiner/Images/CrazyDave.png")
{
    coin += coin_;
    numProp = 4;
    ui->setupUi(this);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    level= new Level(nullptr, levelNum);

    // 播放BGM
    shop_bgm_player = new QSoundEffect(this);
    shop_bgm_player->setSource(QUrl::fromLocalFile("../goldMiner/Music/shop_bgm.wav"));
    shop_bgm_player->setLoopCount(QSoundEffect::Infinite);
    shop_bgm_player->play();

    Dave_player = new QSoundEffect(this);

    QTimer *Timer = new QTimer(this);
    connect(Timer, &QTimer::timeout, this, &Shop::updateTimer);
    Timer->start(1000);

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
    QPushButton* button[3] = {ui->pushButton,ui->pushButton_2,ui->pushButton_3};
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

void Shop::start()
{
    if(levelNum == 2)
    {
        Dave_player->setSource(QUrl::fromLocalFile("../goldMiner/Music/DaveSpeak3.wav"));
        Dave_player->setLoopCount(1);
        Dave_player->play();
        ui->daveLabel->setText("你好，我的邻居");
    }
    else
    {
        Dave_player = new QSoundEffect(this);
        Dave_player->setSource(QUrl::fromLocalFile("../goldMiner/Music/DaveSpeak3.wav"));
        Dave_player->setLoopCount(1);
        Dave_player->play();
        ui->daveLabel->setText("买点东西吧");
    }
}

void Shop::updateTimer()
{
    elaspedTime += 1;
    if(levelNum == 2)
    {
        if(elaspedTime == 2)
        {
            Dave_player->setSource(QUrl::fromLocalFile("../goldMiner/Music/DaveSpeak4.wav"));
            Dave_player->play();
            ui->daveLabel->setText("为什么我会在\n地下开商店?");
        }
        if(elaspedTime == 4)
        {
            Dave_player->setSource(QUrl::fromLocalFile("../goldMiner/Music/DaveSpeak1.wav"));
            Dave_player->play();
            ui->daveLabel->setText("因为我疯了!");
        }
        if(elaspedTime == 6)
        {
            ui->daveLabel->setText("买点东西吧");
        }
    }
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

void Shop::setDaveText(int num)
{
    switch(num)
    {
    case 0:
        ui->daveLabel->setText("砰砰砰!!!");
        break;
    case 1:
        ui->daveLabel->setText("这个药水的原料\n是我家花园的植物");
        break;
    case 2:
        ui->daveLabel->setText("你居然要用金钱\n换时间,你是不是在\n和魔鬼做交易!");
        break;
    case 3:
        ui->daveLabel->setText("为什么会有人\n要半份的关卡?");
        break;
    }
}

void Shop::on_pushButton_clicked()
{
    Dave_player->setSource(QUrl::fromLocalFile(daveSpeak[num[0]]));
    Dave_player->play();
    setDaveText(num[0]);
    buyProp(num[0]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton->setEnabled(false);
    modifyButton();
}

void Shop::on_pushButton_2_clicked()
{
    Dave_player->setSource(QUrl::fromLocalFile(daveSpeak[num[1]]));
    Dave_player->play();
    setDaveText(num[1]);
    buyProp(num[1]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton_2->setEnabled(false);
    modifyButton();
}


void Shop::on_pushButton_3_clicked()
{
    Dave_player->setSource(QUrl::fromLocalFile(daveSpeak[num[2]]));
    Dave_player->play();
    setDaveText(num[2]);
    buyProp(num[2]);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    ui->pushButton_3->setEnabled(false);
    modifyButton();
}


