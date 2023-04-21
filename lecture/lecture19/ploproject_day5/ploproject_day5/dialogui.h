#ifndef DIALOGUI_H
#define DIALOGUI_H

#include <QDialog>

namespace Ui {
class DialogUI;
}

class DialogUI : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUI(QWidget *parent = nullptr);
    ~DialogUI();

    int get_number_points();

private slots:
    void on_butt_submit_clicked();

private:
    Ui::DialogUI *ui;
    int number_points_;
};

#endif // DIALOGUI_H
