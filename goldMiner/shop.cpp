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
    levelNum(levelNum_)
{
    coin += coin_;
    numProp = 4;
    ui->setupUi(this);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    level= new Level(nullptr, levelNum);
    int index = 0;
    while (true){
        int randomNum = QRandomGenerator::global()->bounded(0, numProp);
        if (index == 0){
            num1 = randomNum;
        }
        else if(index == 1){
            if (randomNum != num1){
                num2 = randomNum;
            }
            else{
                continue;
            }
        }
        else{
            if (randomNum != num1 && num2 != randomNum){
                num3 = randomNum;
                break;
            }
            else{
                continue;
            }
        }
        index++;
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
    level->show();
    this->hide();
}

void Shop::on_pushButton_clicked()
{
    switch (num1) {
    case 0:// 炸药
        if (coin >= 500){
            coin -= 500;
            Bomb::bombNum += 1;
        }
        break;
    case 1:// 增加钩子速度
        if (coin >= 2000){
            coin -= 2000;
            level->hook->multiplier = 1.2;
        }
        break;
    case 2:// 增加时间
        if (coin >= 1000){
            coin -= 1000;
            level->restTime += 15;
        }
        break;
    case 3:// 减半
        if (coin >= 5000){
            coin -= 5000;
            level->restTime /= 2;
            level->goalScore /= 2;
            level->ui->goalScoreLabel->setText(QString("目标分数:%1").arg(level->goalScore));
        }
        break;
    default:
        break;
    }
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    num1 = 1e9;
}


void Shop::on_pushButton_2_clicked()
{
    switch (num2) {
    case 0:// 炸药
        if (coin >= 500){
            coin -= 500;
            Bomb::bombNum += 1;
        }
        break;
    case 1:// 增加钩子速度
        if (coin >= 2000){
            coin -= 2000;
            level->hook->multiplier = 1.2;
        }
        break;
    case 2:// 增加时间
        if (coin >= 1000){
            coin -= 1000;
            level->restTime += 15;
        }
        break;
    case 3:// 减半
        if (coin >= 5000){
            coin -= 5000;
            level->restTime /= 2;
            level->goalScore /= 2;
            level->ui->goalScoreLabel->setText(QString("目标分数:%1").arg(level->goalScore));
        }
        break;
    default:
        break;
    }
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    num2 = 1e9;
}


void Shop::on_pushButton_3_clicked()
{
    switch (num3) {
    case 0:// 炸药
        if (coin >= 500){
            coin -= 500;
            Bomb::bombNum += 1;
        }
        break;
    case 1:// 增加钩子速度
        if (coin >= 2000){
            coin -= 2000;
            level->hook->multiplier = 1.2;
        }
        break;
    case 2:// 增加时间
        if (coin >= 1000){
            coin -= 1000;
            level->restTime += 15;
        }
        break;
    case 3:// 减半
        if (coin >= 5000){
            coin -= 5000;
            level->restTime /= 2;
            level->goalScore /= 2;
            level->ui->goalScoreLabel->setText(QString("目标分数:%1").arg(level->goalScore));
        }
        break;
    default:
        break;
    }
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    num3 = 1e9;
}


