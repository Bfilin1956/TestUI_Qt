#include "calendar.h"
#include <QLabel>
#include <QFont>
#include "custombutton.h"

Calendar::Calendar(QWidget *parent) : QFrame(parent), currentDate(QDate::currentDate()) {
    setGeometry(10, 10, 290, 300);
    setStyleSheet("background-color: #e87352;");

    CustomButton *Last = new CustomButton(this, QColor(232,115,82));
    Last->setButtonIcon(QPixmap("C:/Users/bfili/Downloads/free-icon-left-10289680(1).png"));
    Last->setGeometry(20, 20, 30, 30);
    connect(Last, &CustomButton::clicked, this, &Calendar::last);

    CustomButton *Next = new CustomButton(this, QColor(232,115,82));
    Next->setButtonIcon(QPixmap("C:/Users/bfili/Downloads/free-icon-next-10289684(1).png"));
    Next->setGeometry(240, 20, 30, 30);
    connect(Next, &CustomButton::clicked, this, &Calendar::next);

    monthLabel = new QLabel(this);
    monthLabel->setGeometry(80, 20, 150, 30);
    monthLabel->setAlignment(Qt::AlignCenter);
    monthLabel->setFont(QFont("Segoe UI", 14, QFont::Bold));
    monthLabel->setStyleSheet("color: white;");
    monthLabel->setText(currentDate.toString("MMMM yyyy")); // Устанавливаем текущий месяц

    QStringList headdays = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};
    for (unsigned int i = 0; i < 7; i++) {
        QLabel *lbl = new QLabel(headdays.at(i), this);
        lbl->setGeometry(30 * i + 15, 60, 30, 30);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setFont(QFont("Segoe UI", 14, QFont::Bold));
        lbl->setStyleSheet("color: white;");
    }
    updateCalendar();
}

void Calendar::next() {
    currentDate = currentDate.addMonths(1);
    updateCalendar();
    monthLabel->setText(currentDate.toString("MMMM yyyy"));
}

void Calendar::last() {
    currentDate = currentDate.addMonths(-1);
    monthLabel->setText(currentDate.toString("MMMM yyyy"));
    updateCalendar();
}

void Calendar::updateCalendar() {
    for (QLabel *lbl : dayLabels) {
        lbl->deleteLater();
    }
    dayLabels.clear();

    QDate firstDayOfMonth(currentDate.year(), currentDate.month(), 1);
    int dayOfWeek = firstDayOfMonth.dayOfWeek() - 1;
    int daysInMonth = currentDate.daysInMonth();
    QDate today = QDate::currentDate();


    int row = 1;
    int col = dayOfWeek;
    for (int day = 1; day <= daysInMonth; day++) {
        QLabel *lbl = new QLabel(QString::number(day), this);
        lbl->setGeometry(30 * col + 15, 30 * row + 65, 30, 30);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setFont(QFont("Segoe UI", 12, QFont::Normal));

        if (currentDate.year() == today.year() &&
            currentDate.month() == today.month() &&
            day == today.day()) {
            lbl->setStyleSheet("color: black; background-color: white; border-radius: 15px;");
        } else {
            lbl->setStyleSheet("color: white; background-color: #E35931; border-radius: 15px;");
        }

        dayLabels.append(lbl);

        col++;
        if (col == 7) {
            col = 0;
            row++;
        }
    }
}

