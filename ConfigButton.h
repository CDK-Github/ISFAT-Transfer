#ifndef CONFIGBUTTON_H
#define CONFIGBUTTON_H

#include "qpushbutton.h"
#include <QtGui>

class ConfigButton : public QPushButton
{
    Q_OBJECT
public:
    ConfigButton(QPushButton *parent = 0);
};

#endif // CONFIGBUTTON_H
