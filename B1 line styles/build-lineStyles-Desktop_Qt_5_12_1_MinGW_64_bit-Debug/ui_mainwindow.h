/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *l;
    QLineEdit *x1;
    QLineEdit *y1;
    QLineEdit *x2;
    QLineEdit *y2;
    QComboBox *style;
    QPushButton *pushButton_2;
    QSpinBox *thickness;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(580, 442);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 280, 97, 31));
        l = new QLabel(centralWidget);
        l->setObjectName(QString::fromUtf8("l"));
        l->setGeometry(QRect(200, 60, 300, 300));
        x1 = new QLineEdit(centralWidget);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(10, 10, 113, 33));
        y1 = new QLineEdit(centralWidget);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setGeometry(QRect(140, 10, 113, 33));
        x2 = new QLineEdit(centralWidget);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(290, 10, 113, 33));
        y2 = new QLineEdit(centralWidget);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setGeometry(QRect(420, 10, 113, 33));
        style = new QComboBox(centralWidget);
        style->addItem(QString());
        style->addItem(QString());
        style->addItem(QString());
        style->addItem(QString());
        style->addItem(QString());
        style->setObjectName(QString::fromUtf8("style"));
        style->setGeometry(QRect(80, 60, 83, 29));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 330, 97, 31));
        thickness = new QSpinBox(centralWidget);
        thickness->setObjectName(QString::fromUtf8("thickness"));
        thickness->setGeometry(QRect(100, 110, 60, 33));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 41, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 71, 16));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 160, 131, 111));
        textEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "draw", nullptr));
        l->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        x1->setText(QApplication::translate("MainWindow", "x1", nullptr));
        y1->setText(QApplication::translate("MainWindow", "y1", nullptr));
        x2->setText(QApplication::translate("MainWindow", "x2", nullptr));
        y2->setText(QApplication::translate("MainWindow", "y2", nullptr));
        style->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        style->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        style->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        style->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));
        style->setItemText(4, QApplication::translate("MainWindow", "5", nullptr));

        pushButton_2->setText(QApplication::translate("MainWindow", "clear", nullptr));
        label->setText(QApplication::translate("MainWindow", "style :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "thickness :", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. SOLID LINE</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. DASH LINE</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. DASH SOT LINE</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. DOTTED LINE</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-"
                        "indent:0px;\">5. THICK SOLID LINE</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
