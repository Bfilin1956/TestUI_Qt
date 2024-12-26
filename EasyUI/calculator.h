#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>
#include <QColor>
#include <QPalette>
#include <QApplication>
#include <QJSEngine>

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    QLineEdit *display;
    QPushButton *buttons[20];
    QPushButton *buttonDelete;
    QPushButton *buttonClear;

    static constexpr int positions[20][2] = {
        {0, 350}, {80, 350}, {160, 350}, {240, 350},
        {0, 300}, {80, 300}, {160, 300}, {240, 300},
        {0, 250}, {80, 250}, {160, 250}, {240, 250},
        {0, 200}, {80, 200}, {160, 200}, {240, 200},
        {0, 150}, {80, 150}, {160, 150}, {240, 150}
    };

    void onButtonClicked(const QString &text);
    QPushButton* createButton(const QString &text, const QFont &font, int index, int buttonWidth = 80, int buttonHeight = 50);
    double evaluateExpression(const QString &expression);

private slots:
    void handleDelete();
    void handleClear();
};

#endif
