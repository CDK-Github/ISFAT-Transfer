#ifndef CONTACTBUTTON_H
#define CONTACTBUTTON_H

#include "qpushbutton.h"
#include <QtGui>

class ContactButton : public QPushButton
{
    Q_OBJECT
public:
    ContactButton(QPushButton *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
};

#endif // CONTACTBUTTON_H
