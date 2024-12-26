#ifndef EASYUI_H
#define EASYUI_H

#include <QWidget>
#include <QPushButton>
#include <QPainterPath>
#include <QMouseEvent>

#include "frameControl.h"
#include "custombutton.h"
#include "framemaincalendar.h"
#include "framemaincalculator.h"

class EasyUI : public QWidget{
   Q_OBJECT

public:
    explicit EasyUI(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void switchFrame(int index);
private:
    void updateLayout();
    bool m_dragging;
    QPoint m_dragStartPosition;
    QPushButton *closeButton;
    QPushButton *fullscreenButton;
    QPushButton *minimizeButton;
    FrameControl *framecontrol;

    FrameMainCalendar *frameMainCalendar;
    FrameMainCalculator *frameMainCalculator;
};

#endif
