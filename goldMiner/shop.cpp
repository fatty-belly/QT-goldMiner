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
    prop_3mixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bag.png")
{
    coin += coin_;
    numProp = 4;
    ui->setupUi(this);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));
    level= new Level(nullptr, levelNum);

    // 产生三个随机数
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
    // 生成UI图片和文字
    propmixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_1mixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_2mixmap.scaled(20,20,Qt::KeepAspectRatio);
    prop_3mixmap.scaled(20,20,Qt::KeepAspectRatio);
    switch (num1){
    case 0:// 炸药
        ui->label->setText("炸药 $500");
        ui->label_5->setPixmap(propmixmap);
        break;
    case 1:// 大力药水
        ui->label->setText("大力药水 $2000");
        ui->label_5->setPixmap(prop_1mixmap);
        break;
    case 2:// 增加时间
        ui->label->setText("增加15秒 $1000");
        ui->label_5->setPixmap(prop_2mixmap);
        break;
    case 3:// 减半
        ui->label->setText("时间分数减半 $5000");
        ui->label_5->setPixmap(prop_3mixmap);
        break;
    default:
        break;
    }

    switch (num2){
    case 0:// 炸药
        ui->label_2->setText("炸药 $500");
        ui->label_6->setPixmap(propmixmap);
        break;
    case 1:// 大力药水
        ui->label_2->setText("大力药水 $2000");
        ui->label_6->setPixmap(prop_1mixmap);
        break;
    case 2:// 增加时间
        ui->label_2->setText("增加15秒 $1000");
        ui->label_6->setPixmap(prop_2mixmap);
        break;
    case 3:// 减半
        ui->label_2->setText("时间分数减半 $5000");
        ui->label_6->setPixmap(prop_3mixmap);
        break;
    default:
        break;
    }

    switch (num3){
    case 0:// 炸药
        ui->label_3->setText("炸药 $500");
        ui->label_7->setPixmap(propmixmap);
        break;
    case 1:// 大力药水
        ui->label_3->setText("大力药水 $2000");
        ui->label_7->setPixmap(prop_1mixmap);
        break;
    case 2:// 增加时间
        ui->label_3->setText("增加15秒 $1000");
        ui->label_7->setPixmap(prop_2mixmap);
        break;
    case 3:// 减半
        ui->label_3->setText("时间分数减半 $5000");
        ui->label_7->setPixmap(prop_3mixmap);
        break;
    default:
        break;
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
    ui->pushButton->setEnabled(false);
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
    ui->pushButton_2->setEnabled(false);
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
    ui->pushButton_3->setEnabled(false);
}


