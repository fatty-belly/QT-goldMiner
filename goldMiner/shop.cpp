#include "shop.h"
#include "level.h"
#include "ui_shop.h"


int Shop::coin=0;
Shop::Shop(int coin_,QWidget *parent,int levelNum_) :
    QWidget(parent),
    ui(new Ui::Shop),
    levelNum(levelNum_)
{
    coin += coin_;
    ui->setupUi(this);
    ui->coinLabel->setText(QString("金币数量:%1").arg(coin));

    // 生成三个随机数
    int index = 0;
    while (true){
        int randomNum = QRandomGenerator::global()->bounded(0, prop_num);
        if (index == 0){
            num1 = randomNum;
        }
        else if(index == 1){
            if (randomNum != num1)
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
    Level *level= new Level(nullptr, levelNum);
    level->show();
    this->hide();
}

