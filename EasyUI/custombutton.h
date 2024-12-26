#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QColor>

class CustomButton : public QWidget {
    Q_OBJECT
public:
    explicit CustomButton(QWidget *parent = nullptr, const QColor &color = Qt::blue);

    void setButtonColor(const QColor &color);
    void setButtonText(const QString &text);
    void setButtonIcon(const QPixmap &icon);

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QColor m_color;
    QString m_text;
    bool m_pressed;
    QPixmap m_icon;
};

#endif
