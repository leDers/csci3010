/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *butt_mult;
    QPushButton *butt_sign;
    QPushButton *butt_sub;
    QPushButton *butt_add;
    QPushButton *butt_0;
    QPushButton *butt_9;
    QPushButton *butt_6;
    QPushButton *butt_3;
    QPushButton *butt_5;
    QPushButton *butt_dec;
    QPushButton *butt_4;
    QPushButton *butt_1;
    QPushButton *butt_square;
    QPushButton *butt_2;
    QPushButton *butt_8;
    QPushButton *butt_sqrt;
    QPushButton *butt_recipricol;
    QPushButton *butt_7;
    QPushButton *butt_div;
    QPushButton *butt_percent;
    QPushButton *butt_CE;
    QPushButton *butt_backspace;
    QPushButton *butt_clear;
    QLineEdit *display;
    QPushButton *butt_eq;
    QMenuBar *menubar;
    QMenu *menuCalculator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(442, 285);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        butt_mult = new QPushButton(centralwidget);
        butt_mult->setObjectName("butt_mult");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(butt_mult->sizePolicy().hasHeightForWidth());
        butt_mult->setSizePolicy(sizePolicy);
        butt_mult->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_mult, 3, 5, 1, 1);

        butt_sign = new QPushButton(centralwidget);
        butt_sign->setObjectName("butt_sign");
        sizePolicy.setHeightForWidth(butt_sign->sizePolicy().hasHeightForWidth());
        butt_sign->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_sign, 6, 2, 1, 1);

        butt_sub = new QPushButton(centralwidget);
        butt_sub->setObjectName("butt_sub");
        sizePolicy.setHeightForWidth(butt_sub->sizePolicy().hasHeightForWidth());
        butt_sub->setSizePolicy(sizePolicy);
        butt_sub->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_sub, 5, 5, 1, 1);

        butt_add = new QPushButton(centralwidget);
        butt_add->setObjectName("butt_add");
        sizePolicy.setHeightForWidth(butt_add->sizePolicy().hasHeightForWidth());
        butt_add->setSizePolicy(sizePolicy);
        butt_add->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_add, 4, 5, 1, 1);

        butt_0 = new QPushButton(centralwidget);
        butt_0->setObjectName("butt_0");
        sizePolicy.setHeightForWidth(butt_0->sizePolicy().hasHeightForWidth());
        butt_0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_0, 6, 3, 1, 1);

        butt_9 = new QPushButton(centralwidget);
        butt_9->setObjectName("butt_9");
        sizePolicy.setHeightForWidth(butt_9->sizePolicy().hasHeightForWidth());
        butt_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_9, 3, 4, 1, 1);

        butt_6 = new QPushButton(centralwidget);
        butt_6->setObjectName("butt_6");
        sizePolicy.setHeightForWidth(butt_6->sizePolicy().hasHeightForWidth());
        butt_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_6, 4, 4, 1, 1);

        butt_3 = new QPushButton(centralwidget);
        butt_3->setObjectName("butt_3");
        sizePolicy.setHeightForWidth(butt_3->sizePolicy().hasHeightForWidth());
        butt_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_3, 5, 4, 1, 1);

        butt_5 = new QPushButton(centralwidget);
        butt_5->setObjectName("butt_5");
        sizePolicy.setHeightForWidth(butt_5->sizePolicy().hasHeightForWidth());
        butt_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_5, 4, 3, 1, 1);

        butt_dec = new QPushButton(centralwidget);
        butt_dec->setObjectName("butt_dec");
        sizePolicy.setHeightForWidth(butt_dec->sizePolicy().hasHeightForWidth());
        butt_dec->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_dec, 6, 4, 1, 1);

        butt_4 = new QPushButton(centralwidget);
        butt_4->setObjectName("butt_4");
        sizePolicy.setHeightForWidth(butt_4->sizePolicy().hasHeightForWidth());
        butt_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_4, 4, 2, 1, 1);

        butt_1 = new QPushButton(centralwidget);
        butt_1->setObjectName("butt_1");
        sizePolicy.setHeightForWidth(butt_1->sizePolicy().hasHeightForWidth());
        butt_1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_1, 5, 2, 1, 1);

        butt_square = new QPushButton(centralwidget);
        butt_square->setObjectName("butt_square");
        sizePolicy.setHeightForWidth(butt_square->sizePolicy().hasHeightForWidth());
        butt_square->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        butt_square->setFont(font);
        butt_square->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_square, 2, 3, 1, 1);

        butt_2 = new QPushButton(centralwidget);
        butt_2->setObjectName("butt_2");
        sizePolicy.setHeightForWidth(butt_2->sizePolicy().hasHeightForWidth());
        butt_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_2, 5, 3, 1, 1);

        butt_8 = new QPushButton(centralwidget);
        butt_8->setObjectName("butt_8");
        sizePolicy.setHeightForWidth(butt_8->sizePolicy().hasHeightForWidth());
        butt_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_8, 3, 3, 1, 1);

        butt_sqrt = new QPushButton(centralwidget);
        butt_sqrt->setObjectName("butt_sqrt");
        sizePolicy.setHeightForWidth(butt_sqrt->sizePolicy().hasHeightForWidth());
        butt_sqrt->setSizePolicy(sizePolicy);
        butt_sqrt->setFont(font);
        butt_sqrt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_sqrt, 2, 4, 1, 1);

        butt_recipricol = new QPushButton(centralwidget);
        butt_recipricol->setObjectName("butt_recipricol");
        butt_recipricol->setFont(font);
        butt_recipricol->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_recipricol, 2, 2, 1, 1);

        butt_7 = new QPushButton(centralwidget);
        butt_7->setObjectName("butt_7");
        sizePolicy.setHeightForWidth(butt_7->sizePolicy().hasHeightForWidth());
        butt_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(butt_7, 3, 2, 1, 1);

        butt_div = new QPushButton(centralwidget);
        butt_div->setObjectName("butt_div");
        sizePolicy.setHeightForWidth(butt_div->sizePolicy().hasHeightForWidth());
        butt_div->setSizePolicy(sizePolicy);
        butt_div->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_div, 2, 5, 1, 1);

        butt_percent = new QPushButton(centralwidget);
        butt_percent->setObjectName("butt_percent");
        butt_percent->setFont(font);
        butt_percent->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_percent, 1, 2, 1, 1);

        butt_CE = new QPushButton(centralwidget);
        butt_CE->setObjectName("butt_CE");
        butt_CE->setFont(font);
        butt_CE->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_CE, 1, 3, 1, 1);

        butt_backspace = new QPushButton(centralwidget);
        butt_backspace->setObjectName("butt_backspace");
        butt_backspace->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_backspace, 1, 5, 1, 1);

        butt_clear = new QPushButton(centralwidget);
        butt_clear->setObjectName("butt_clear");
        sizePolicy.setHeightForWidth(butt_clear->sizePolicy().hasHeightForWidth());
        butt_clear->setSizePolicy(sizePolicy);
        butt_clear->setFont(font);
        butt_clear->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #D8BFD8;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_clear, 1, 4, 1, 1);

        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(14);
        display->setFont(font1);
        display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(display, 0, 2, 1, 4);

        butt_eq = new QPushButton(centralwidget);
        butt_eq->setObjectName("butt_eq");
        sizePolicy.setHeightForWidth(butt_eq->sizePolicy().hasHeightForWidth());
        butt_eq->setSizePolicy(sizePolicy);
        butt_eq->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFA500;\n"
"	color: #000000; \n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(butt_eq, 6, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 442, 21));
        menuCalculator = new QMenu(menubar);
        menuCalculator->setObjectName("menuCalculator");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuCalculator->menuAction());

        retranslateUi(MainWindow);

        butt_CE->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        butt_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        butt_sign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        butt_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        butt_add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        butt_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        butt_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        butt_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        butt_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        butt_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        butt_dec->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        butt_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        butt_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        butt_square->setText(QCoreApplication::translate("MainWindow", "x^2", nullptr));
        butt_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        butt_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        butt_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt(x)", nullptr));
        butt_recipricol->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        butt_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        butt_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        butt_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        butt_CE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
        butt_backspace->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        butt_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        display->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        butt_eq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        menuCalculator->setTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
