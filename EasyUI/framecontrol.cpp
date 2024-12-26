#include "framecontrol.h"

FrameControl::FrameControl(QWidget *parent)
    : QFrame(parent) {
    setGeometry(0, 20, 280, 702);
    setStyleSheet("background-color: #201f2d;");
}
