#include "endgamedialog.h"
#include "level.h"
#include "shop.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(int addCoin_, int levelNum_, bool win_) :
    ui(new Ui::EndGameDialog),
    levelNum(levelNum_),
    win(win_),
    addCoin(addCoin_)
{
    ui->setupUi(this);
    if(!win)
    {
        ui->label->setText(QString("你没有达到目标分数\n游戏结束!\n"));
        ui->pushButton->setText("结束游戏");
    }
    else if(levelNum < Level::totalLevelNum)
    {
        ui->label->setText(QString("你赢了!\n你获得了金币:%1").arg(addCoin));
        ui->pushButton->setText("进入商店");
    }
    else
    {
        ui->label->setText(QString("你获得了游戏的最终胜利!\n"));
        ui->pushButton->setText("结束游戏");
    }

    if(win && levelNum == 3)
    {
        ui->bombLabel->setText("你获得了5个炸药补给:)");
    }
    else
    {
        ui->bombLabel->hide();
    }
}

EndGameDialog::~EndGameDialog()
{
    delete ui;
}

void EndGameDialog::on_pushButton_clicked()
{
    close();
    if(win && levelNum < Level::totalLevelNum)
    {
        Shop *shop = new Shop(addCoin, nullptr,levelNum + 1);
        shop->show();
    }
}

