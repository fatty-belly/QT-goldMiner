/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->setEnabled(true);
        StartWindow->resize(1308, 1149);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(\"/Users/zhaohaonan/Desktop/\345\214\227\345\244\247\350\265\204\346\226\231/Coding/C++/\347\250\213\345\272\217\350\256\276\350\256\241\345\256\236\344\271\240/QT-goldMiner/goldMiner/Images/begin.png\");\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 280, 501, 211));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(\"/Users/zhaohaonan/Desktop/\345\214\227\345\244\247\350\265\204\346\226\231/Coding/C++/\347\250\213\345\272\217\350\256\276\350\256\241\345\256\236\344\271\240/QT-goldMiner/goldMiner/Images/start.png\");\n"
""));
        StartWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(StartWindow);
        statusBar->setObjectName("statusBar");
        StartWindow->setStatusBar(statusBar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
