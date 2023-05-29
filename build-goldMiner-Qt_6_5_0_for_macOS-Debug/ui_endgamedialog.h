/********************************************************************************
** Form generated from reading UI file 'endgamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEDIALOG_H
#define UI_ENDGAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndGameDialog
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *bombLabel;

    void setupUi(QDialog *EndGameDialog)
    {
        if (EndGameDialog->objectName().isEmpty())
            EndGameDialog->setObjectName("EndGameDialog");
        EndGameDialog->resize(400, 300);
        label = new QLabel(EndGameDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 301, 141));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(EndGameDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 250, 80, 18));
        bombLabel = new QLabel(EndGameDialog);
        bombLabel->setObjectName("bombLabel");
        bombLabel->setGeometry(QRect(80, 199, 241, 31));
        QFont font1;
        font1.setPointSize(14);
        bombLabel->setFont(font1);
        bombLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(EndGameDialog);

        QMetaObject::connectSlotsByName(EndGameDialog);
    } // setupUi

    void retranslateUi(QDialog *EndGameDialog)
    {
        EndGameDialog->setWindowTitle(QCoreApplication::translate("EndGameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EndGameDialog", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("EndGameDialog", "PushButton", nullptr));
        bombLabel->setText(QCoreApplication::translate("EndGameDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndGameDialog: public Ui_EndGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEDIALOG_H
