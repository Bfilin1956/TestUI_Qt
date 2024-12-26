#include "easyui.h"
#include <QListWidget>

EasyUI::EasyUI(QWidget *parent) : QWidget(parent), m_dragging(false){
    setWindowFlags(Qt::FramelessWindowHint);

    setStyleSheet("background-color: #31303B; border-radius: 0px;");
    resize(1280,720);

    closeButton = new QPushButton("", this);
    closeButton->setGeometry(width()-20, 2, 16, 16);
    closeButton->setStyleSheet("background-color: red; border-radius: 8px;");
    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);

    fullscreenButton = new QPushButton("", this);
    fullscreenButton->setGeometry(width()-40, 2, 16, 16);
    fullscreenButton->setStyleSheet("background-color: yellow; border-radius: 8px;");
    connect(fullscreenButton, &QPushButton::clicked, this, [this]() {
        if (this->isFullScreen()) {
            this->showNormal();
            updateLayout();
        } else {
            this->showFullScreen();
            updateLayout();
        }
    });

    minimizeButton = new QPushButton("", this);
    minimizeButton->setGeometry(width()-60, 2, 16, 16);
    minimizeButton->setStyleSheet("background-color: green; border-radius: 8px;");
    connect(minimizeButton, &QPushButton::clicked, this, &QWidget::showMinimized);

    frameMainCalendar = new FrameMainCalendar(this);
    frameMainCalendar->hide();

    frameMainCalculator = new FrameMainCalculator(this);
    frameMainCalculator->hide();

    framecontrol = new FrameControl(this);
    QColor colorframecontrol = QColor(32,31,45);

    CustomButton *settings = new CustomButton(framecontrol, colorframecontrol);
    settings->setButtonText("Setting");
    settings->setGeometry(0,0,280,100);


    CustomButton *сalendar = new CustomButton(framecontrol, colorframecontrol);
    сalendar->setButtonText("Calendar");
    сalendar->setGeometry(0,100,280,100);
    connect(сalendar, &CustomButton::clicked, this, [this]() {
        switchFrame(0);
    });

    CustomButton *calculator = new CustomButton(framecontrol, colorframecontrol);
    calculator->setButtonText("Сalculator");
    calculator->setGeometry(0,200,280,100);
    connect(calculator, &CustomButton::clicked, this, [this]() {switchFrame(1);});
}
void EasyUI::switchFrame(int index) {
    frameMainCalendar->hide();
    frameMainCalculator->hide();

    switch (index) {
    case 0:
        frameMainCalendar->show();
        break;
    case 1:
        frameMainCalculator->show();
        break;
    default:
        break;
    }
}
void EasyUI::updateLayout() {
    closeButton->move(width()-20, 2);
    fullscreenButton->move(width()-38, 2);
    minimizeButton->move(width()-56, 2);
    framecontrol->resize(280, height()-18);
    frameMainCalendar->resize(width()-280, height()-18);

}
void EasyUI::paintEvent(QPaintEvent *event)  {
    QPainterPath path;
    path.addRoundedRect(rect(), 20, 20);
    QRegion maskRegion(path.toFillPolygon().toPolygon());
    setMask(maskRegion);
    QWidget::paintEvent(event);
}

void EasyUI::mousePressEvent(QMouseEvent *event)  {
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragStartPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void EasyUI::mouseMoveEvent(QMouseEvent *event)  {
    if (m_dragging) {
        move(event->globalPosition().toPoint() - m_dragStartPosition);
        event->accept();
    }
}

void EasyUI::mouseReleaseEvent(QMouseEvent *event)  {
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();
    }
}
