#include "calendar.h"
#include "cloud.h"
#include "framemaincalendar.h"

FrameMainCalendar::FrameMainCalendar(QWidget *parent) : QFrame(parent) {
    setGeometry(280, 20, 1000, 702);
    setStyleSheet("background-color: #16171b;");
    Calendar *x1 = new Calendar(this);
    Cloud *x2 = new Cloud(this);
}

