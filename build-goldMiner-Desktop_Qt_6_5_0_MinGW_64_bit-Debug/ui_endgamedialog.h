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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EndGameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *EndGameDialog)
    {
        if (EndGameDialog->objectName().isEmpty())
            EndGameDialog->setObjectName("EndGameDialog");
        EndGameDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(EndGameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(EndGameDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 70, 241, 111));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(EndGameDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EndGameDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EndGameDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EndGameDialog);
    } // setupUi

    void retranslateUi(QDialog *EndGameDialog)
    {
        EndGameDialog->setWindowTitle(QCoreApplication::translate("EndGameDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        buttonBox->setToolTip(QCoreApplication::translate("EndGameDialog", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("EndGameDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndGameDialog: public Ui_EndGameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEDIALOG_H
