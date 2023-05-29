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

