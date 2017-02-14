#include "contactwindow.h"

contactWindow::contactWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactWindow)
{
    ui->setupUi(this);
}

contactWindow::~contactWindow()
{
    delete ui;
}
