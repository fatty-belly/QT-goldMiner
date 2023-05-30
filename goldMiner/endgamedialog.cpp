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

    if(win)
    {
        switch(levelNum)
        {
        case 1:
            ui->hintLabel->setText("下面是比较简单的第二关~, 总共6关");
            break;
        case 2:
            ui->hintLabel->setText("下面是第三关，共六关\n一闪一闪亮晶晶，满地都是小钻石~");
            break;
        case 3:
            ui->hintLabel->setText("下面是第四关，共六关\n地震了，满地都是碎石");
            break;
        case 4:
            ui->hintLabel->setText("下面是第五关，共六关\n为什么地下会下雪？");
            break;
        case 5:
            ui->hintLabel->setText("下面是最后一关！\n时间就是生命，我的朋友");
            break;
        }


    }
    else
    {
        ui->hintLabel->hide();
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

