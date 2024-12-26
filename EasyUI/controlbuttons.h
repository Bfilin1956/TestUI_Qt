#ifndef CONTROLBUTTONS_H
#define CONTROLBUTTONS_H

#include <QFrame>
#include "easyui.h"
class controlbuttons : protected EasyUI
{
    Q_OBJECT
public:
    controlbuttons();

private:
    QFrame *frame;
};

#endif
