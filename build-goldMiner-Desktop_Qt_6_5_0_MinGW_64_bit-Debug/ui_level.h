/********************************************************************************
** Form generated from reading UI file 'level.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL_H
#define UI_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level
{
public:
    QLabel *minerLabel;
    QLabel *hookLabel;
    QLabel *scoreLabel;
    QLabel *timeLabel;
    QLabel *bombNumLabel;

    void setupUi(QWidget *Level)
    {
        if (Level->objectName().isEmpty())
            Level->setObjectName("Level");
        Level->resize(719, 455);
        Level->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 217, 140);"));
        minerLabel = new QLabel(Level);
        minerLabel->setObjectName("minerLabel");
        minerLabel->setGeometry(QRect(315, 0, 91, 81));
        minerLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        minerLabel->setPixmap(QPixmap(QString::fromUtf8("Images/goldminer.png")));
        minerLabel->setScaledContents(true);
        hookLabel = new QLabel(Level);
        hookLabel->setObjectName("hookLabel");
        hookLabel->setGeometry(QRect(300, 30, 101, 101));
        hookLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        hookLabel->setPixmap(QPixmap(QString::fromUtf8("Images/hook.png")));
        hookLabel->setScaledContents(true);
        scoreLabel = new QLabel(Level);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(40, 20, 151, 51));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 217, 140, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        scoreLabel->setPalette(palette);
        QFont font;
        font.setPointSize(20);
        scoreLabel->setFont(font);
        scoreLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        timeLabel = new QLabel(Level);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(480, 10, 161, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        timeLabel->setPalette(palette1);
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        bombNumLabel = new QLabel(Level);
        bombNumLabel->setObjectName("bombNumLabel");
        bombNumLabel->setGeometry(QRect(480, 50, 211, 51));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        bombNumLabel->setPalette(palette2);
        bombNumLabel->setFont(font);
        bombNumLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        retranslateUi(Level);

        QMetaObject::connectSlotsByName(Level);
    } // setupUi

    void retranslateUi(QWidget *Level)
    {
        Level->setWindowTitle(QCoreApplication::translate("Level", "Form", nullptr));
        minerLabel->setText(QString());
        hookLabel->setText(QString());
        scoreLabel->setText(QCoreApplication::translate("Level", "TextLabel", nullptr));
        timeLabel->setText(QCoreApplication::translate("Level", "TextLabel", nullptr));
        bombNumLabel->setText(QCoreApplication::translate("Level", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Level: public Ui_Level {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL_H
