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

    void setupUi(QWidget *Shop)
    {
        if (Shop->objectName().isEmpty())
            Shop->setObjectName("Shop");
        Shop->resize(467, 300);
        pushButton = new QPushButton(Shop);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 180, 80, 18));
        pushButton_2 = new QPushButton(Shop);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 180, 80, 18));
        pushButton_3 = new QPushButton(Shop);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(340, 180, 80, 18));
        label = new QLabel(Shop);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 210, 81, 51));
        label_2 = new QLabel(Shop);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 210, 81, 41));
        label_3 = new QLabel(Shop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 210, 81, 41));
        nextLevelButton = new QPushButton(Shop);
        nextLevelButton->setObjectName("nextLevelButton");
        nextLevelButton->setGeometry(QRect(360, 20, 80, 18));
        label_4 = new QLabel(Shop);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 20, 91, 31));
        coinLabel = new QLabel(Shop);
        coinLabel->setObjectName("coinLabel");
        coinLabel->setGeometry(QRect(30, 20, 121, 31));

        retranslateUi(Shop);

        QMetaObject::connectSlotsByName(Shop);
    } // setupUi

    void retranslateUi(QWidget *Shop)
    {
        Shop->setWindowTitle(QCoreApplication::translate("Shop", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Shop", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Shop", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Shop", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
        nextLevelButton->setText(QCoreApplication::translate("Shop", "\344\270\213\344\270\200\345\205\263", nullptr));
        label_4->setText(QCoreApplication::translate("Shop", "\345\225\206\345\272\227", nullptr));
        coinLabel->setText(QCoreApplication::translate("Shop", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop: public Ui_Shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
