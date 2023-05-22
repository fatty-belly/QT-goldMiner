#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class EndGameDialog;
}

class EndGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameDialog(int score);
    ~EndGameDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::EndGameDialog *ui;
};

#endif // ENDGAMEDIALOG_H
