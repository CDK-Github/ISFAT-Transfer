#include "ContactMail.h"
#include "smtp.h"

#include <QDesktopWidget>
#include <QFormLayout>

ContactMail::ContactMail(QWidget *parent) : QWidget(parent)
{
    setFixedSize(512,512);
    setWindowFlags(Qt::FramelessWindowHint);

    QFormLayout *mailLayout = new QFormLayout(this);

    this->show();
    this->CenterOnScreen();
}

ContactMail::~ContactMail()
{

}
void ContactMail::CenterOnScreen()
{
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);

    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();

    move(screenCenterX - width() / 2, screenCenterY - height() / 2 );
}
