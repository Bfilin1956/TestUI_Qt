#include "custombutton.h"
#include <QPainter>
#include <QMouseEvent>

CustomButton::CustomButton(QWidget *parent, const QColor &color)
    : QWidget(parent), m_pressed(false), m_text(""), m_color(color) {
    resize(100, 40);
}

void CustomButton::setButtonColor(const QColor &color) {
    m_color = color;
    update();
}

void CustomButton::setButtonText(const QString &text) {
    m_text = text;
    update();
}

void CustomButton::setButtonIcon(const QPixmap &icon) {
    m_icon = icon;
    update();
}

void CustomButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF rect = this->rect();
    painter.setBrush(m_pressed ? QColor(255, 193, 0) : m_color);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect, 5, 5);

    if (!m_icon.isNull()) {
        int iconSize = qMin(width(), height()) - 10;
        QRect iconRect((width() - iconSize) / 2, (height() - iconSize) / 2, iconSize, iconSize);
        painter.drawPixmap(iconRect, m_icon);
    }

    if (!m_text.isEmpty()) {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Segoe UI", 14, QFont::Normal));
        painter.drawText(rect, Qt::AlignCenter, m_text);
    }
}

void CustomButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_pressed = true;
        update();
    }
}

void CustomButton::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && m_pressed) {
        m_pressed = false;
        update();
        emit clicked();
    }
}
