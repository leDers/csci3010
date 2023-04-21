#include "setupdialog.h"
#include "qpushbutton.h"
#include "ui_setupdialog.h"

SetupDialog::SetupDialog(QWidget* parent)
    : QDialog(parent), spinBox_(new QSpinBox(this)),
      layout_(new QVBoxLayout(this))
{
    // Set up the spin box
    spinBox_->setRange(2, 4);
    spinBox_->setValue(1);

    // Add the spin box and layout to the dialog
    layout_->addWidget(spinBox_);
    setLayout(layout_);

    // Connect the valueChanged() signal of the spin box to a slot
    connect(spinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, &SetupDialog::onSpinBoxValueChanged);

    // Call the slot to create the initial QLineEdit objects
    onSpinBoxValueChanged(spinBox_->value());

    namesInputed = false;
    // Create a Save button
    saveButton_ = new QPushButton(tr("Save"), this);

    // Connect the Save button's clicked() signal to the saveAndClose() slot
    connect(saveButton_, &QPushButton::clicked, this, &SetupDialog::saveAndClose);

    // Add a spacer item to push the Save button to the bottom of the layout
    layout_->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout_->addWidget(saveButton_);
    QDialog::setLayout(layout_);
}

void SetupDialog::onSpinBoxValueChanged(int value)
{
    // Delete any existing QLineEdit objects
    for (QLineEdit* lineEdit : lineEdits_) {
        layout_->removeWidget(lineEdit);
        delete lineEdit;
    }
    lineEdits_.clear();

    // Create new QLineEdit objects based on the spin box value
    for (int i = 0; i < value; i++) {
        QLineEdit* lineEdit = new QLineEdit(this);
        layout_->addWidget(lineEdit);
        lineEdits_.append(lineEdit);
    }

    // Update the dialog layout
    adjustSize();
}

void SetupDialog::saveAndClose()
{
    // Save the data here
    for (QLineEdit* lineEdit : lineEdits_) {
        pNames_.append(lineEdit->text());
    }

    qDebug() << "Name list:" << pNames_;

    namesInputed = true;
    // Close the dialog
    accept();
}

int SetupDialog::getSpinBoxValue()
{
    return spinBox_->value();
}

QStringList SetupDialog::getPNames()
{
    return pNames_;
}

bool SetupDialog::getNamesInputed(){
    return namesInputed;
}
