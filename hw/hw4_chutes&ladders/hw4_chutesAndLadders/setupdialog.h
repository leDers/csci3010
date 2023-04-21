#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include "qspinbox.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDialog>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
//    explicit SetupDialog(QWidget *parent = nullptr);
//    ~SetupDialog();

    SetupDialog(QWidget* parent = nullptr);

    int getSpinBoxValue();
    QList<QLineEdit *> getlineEdit();
    QStringList getPNames();
    bool getNamesInputed();

private slots:
    void onSpinBoxValueChanged(int value);
    void saveAndClose();

private:
    Ui::SetupDialog *ui;

    QSpinBox* spinBox_;
    QVBoxLayout* layout_;
    QList<QLineEdit*> lineEdits_;
    QStringList pNames_;

    QPushButton* saveButton_;

    bool namesInputed;
};

#endif // SETUPDIALOG_H
