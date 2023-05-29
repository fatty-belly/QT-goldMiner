#include "endgamedialog.h"
#include "level.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(int score, int levelNum_, bool win_) :
    ui(new Ui::EndGameDialog),
    levelNum(levelNum_),
    win(win_)
{
    ui->setupUi(this);
    if(!win)
    {
        ui->label->setText(QString("你没有达到目标分数\n游戏结束!\n你本关的得分是:%1").arg(score));
        ui->pushButton->setText("结束游戏");
    }
    else if(levelNum < Level::totalLevelNum)
    {
        ui->label->setText(QString("你赢了!\n你本关的得分是:%1").arg(score));
        ui->pushButton->setText("下一关");
    }
    else
    {
        ui->label->setText(QString("你获得了游戏的最终胜利!\n你本关的得分是:%1").arg(score));
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
        Level *level = new Level(nullptr,levelNum + 1);
        level->show();
    }
}

