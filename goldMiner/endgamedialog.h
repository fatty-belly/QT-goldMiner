#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include "qabstractbutton.h"
#include "qsoundeffect.h"
#include <QDialog>

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    friend class Level;
    explicit EndGameDialog(int addCoin_, int levelNum_, bool win_, QSoundEffect * level_player_);
    ~EndGameDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EndGameDialog *ui;
    int levelNum;
    bool win;
    int addCoin;
    QSoundEffect *level_player;
};

#endif // ENDGAMEDIALOG_H
