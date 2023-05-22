#include "endgamedialog.h"
#include "ui_endgamedialog.h"

EndGameDialog::EndGameDialog(int score) :
    ui(new Ui::EndGameDialog)
{
    ui->setupUi(this);
    ui->label->setText(QString("游戏结束!\n你的得分是:%1").arg(score));
}

EndGameDialog::~EndGameDialog()
{
    delete ui;
}

void EndGameDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    close();
}

