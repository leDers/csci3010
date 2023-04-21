/********************************************************************************
** Form generated from reading UI file 'dialogui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUI_H
#define UI_DIALOGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogUI
{
public:
    QLabel *textLabel;
    QSpinBox *value_spinBox;
    QPushButton *butt_submit;

    void setupUi(QDialog *DialogUI)
    {
        if (DialogUI->objectName().isEmpty())
            DialogUI->setObjectName("DialogUI");
        DialogUI->resize(400, 300);
        textLabel = new QLabel(DialogUI);
        textLabel->setObjectName("textLabel");
        textLabel->setGeometry(QRect(100, 90, 201, 16));
        value_spinBox = new QSpinBox(DialogUI);
        value_spinBox->setObjectName("value_spinBox");
        value_spinBox->setGeometry(QRect(180, 130, 42, 25));
        butt_submit = new QPushButton(DialogUI);
        butt_submit->setObjectName("butt_submit");
        butt_submit->setGeometry(QRect(160, 170, 80, 24));

        retranslateUi(DialogUI);

        QMetaObject::connectSlotsByName(DialogUI);
    } // setupUi

    void retranslateUi(QDialog *DialogUI)
    {
        DialogUI->setWindowTitle(QCoreApplication::translate("DialogUI", "Dialog", nullptr));
        textLabel->setText(QCoreApplication::translate("DialogUI", "Enter Nubmer of Points to Initialize", nullptr));
        butt_submit->setText(QCoreApplication::translate("DialogUI", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogUI: public Ui_DialogUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUI_H
