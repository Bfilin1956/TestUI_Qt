#ifndef CALENDAR_H
#define CALENDAR_H
#include "qlabel.h"
#include <QDate>
#include <QFrame>
#include <QLabel>

class Calendar : public QFrame
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = nullptr);

    void next();
    void last();
private:
    QDate currentDate;
    QLabel *monthLabel;
    QList<QLabel *> dayLabels;
    QStringList headdays = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    void updateCalendar();
};

#endif
