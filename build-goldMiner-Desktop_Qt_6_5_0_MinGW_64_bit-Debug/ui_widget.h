/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QLabel *minerLabel;
    QFrame *frame_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(733, 444);
        Widget->setAcceptDrops(false);
        Widget->setAutoFillBackground(false);
        frame = new QFrame(Widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 731, 81));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        minerLabel = new QLabel(frame);
        minerLabel->setObjectName("minerLabel");
        minerLabel->setEnabled(true);
        minerLabel->setGeometry(QRect(340, 10, 61, 61));
        minerLabel->setPixmap(QPixmap(QString::fromUtf8("Images/goldminer.png")));
        minerLabel->setScaledContents(true);
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 80, 731, 371));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(219, 161, 102);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        minerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
