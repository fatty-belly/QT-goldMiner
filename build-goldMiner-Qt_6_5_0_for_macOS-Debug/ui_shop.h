/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *nextLevelButton;
    QLabel *label_4;
    QLabel *coinLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *Shop)
    {
        if (Shop->objectName().isEmpty())
            Shop->setObjectName("Shop");
        Shop->resize(752, 426);
        Shop->setAutoFillBackground(true);
        Shop->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(Shop);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 270, 80, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoFillBackground(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(Shop);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 270, 80, 31));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setAutoFillBackground(true);
        pushButton_2->setIcon(icon);
        pushButton_3 = new QPushButton(Shop);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(340, 270, 80, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setAutoFillBackground(true);
        pushButton_3->setIcon(icon);
        label = new QLabel(Shop);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 320, 141, 51));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Shop);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 320, 141, 51));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Shop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 320, 141, 51));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);
        nextLevelButton = new QPushButton(Shop);
        nextLevelButton->setObjectName("nextLevelButton");
        nextLevelButton->setGeometry(QRect(350, 20, 91, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(18);
        nextLevelButton->setFont(font);
        label_4 = new QLabel(Shop);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 40, 91, 31));
        label_4->setFont(font);
        coinLabel = new QLabel(Shop);
        coinLabel->setObjectName("coinLabel");
        coinLabel->setGeometry(QRect(30, 40, 141, 41));
        coinLabel->setFont(font);
        label_5 = new QLabel(Shop);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 140, 81, 81));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Shop);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(190, 140, 81, 81));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Shop);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(340, 140, 81, 81));
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(false);
        label_8 = new QLabel(Shop);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(510, 0, 221, 421));

        retranslateUi(Shop);

        QMetaObject::connectSlotsByName(Shop);
    } // setupUi

    void retranslateUi(QWidget *Shop)
    {
        Shop->setWindowTitle(QCoreApplication::translate("Shop", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Shop", "\350\264\255\344\271\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Shop", "\350\264\255\344\271\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Shop", "\350\264\255\344\271\260", nullptr));
        label->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        nextLevelButton->setText(QCoreApplication::translate("Shop", "\344\270\213\344\270\200\345\205\263", nullptr));
        label_4->setText(QCoreApplication::translate("Shop", "\345\225\206\345\272\227", nullptr));
        coinLabel->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop: public Ui_Shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
