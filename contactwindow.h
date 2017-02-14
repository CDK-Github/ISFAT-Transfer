#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QWidget>

namespace Ui {
class contactWindow;
}

class contactWindow : public QWidget
{
    Q_OBJECT

public:
    explicit contactWindow(QWidget *parent = 0);
    ~contactWindow();

private:
    Ui::contactWindow *ui;
};

#endif // CONTACTWINDOW_H
