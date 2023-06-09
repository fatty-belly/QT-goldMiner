#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include "qsoundeffect.h"
#include <QDialog>

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameDialog(int addCoin_, int levelNum_, bool win_);
    ~EndGameDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EndGameDialog *ui;
    int levelNum;
    bool win;
    int addCoin;
    QSoundEffect* endPlayer = new QSoundEffect();
};

#endif // ENDGAMEDIALOG_H
