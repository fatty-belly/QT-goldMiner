/********************************************************************************
** Form generated from reading UI file 'levelWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELWINDOW_H
#define UI_LEVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelWindow
{
public:
    QFrame *frame;
    QLabel *minerLabel;
    QFrame *frame_2;

    void setupUi(QWidget *LevelWindow)
    {
        if (LevelWindow->objectName().isEmpty())
            LevelWindow->setObjectName("LevelWindow");
        LevelWindow->resize(733, 444);
        LevelWindow->setAcceptDrops(false);
        LevelWindow->setAutoFillBackground(false);
        frame = new QFrame(LevelWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 731, 81));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        minerLabel = new QLabel(frame);
        minerLabel->setObjectName("minerLabel");
        minerLabel->setEnabled(true);
        minerLabel->setGeometry(QRect(340, 10, 61, 61));
        minerLabel->setPixmap(QPixmap(QString::fromUtf8("Images/goldminer.png")));
        minerLabel->setScaledContents(true);
        frame_2 = new QFrame(LevelWindow);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 80, 731, 371));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 161, 102);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        retranslateUi(LevelWindow);

        QMetaObject::connectSlotsByName(LevelWindow);
    } // setupUi

    void retranslateUi(QWidget *LevelWindow)
    {
        LevelWindow->setWindowTitle(QCoreApplication::translate("LevelWindow", "Widget", nullptr));
        minerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LevelWindow: public Ui_LevelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELWINDOW_H
