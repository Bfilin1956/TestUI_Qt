#include "Calculator.h"
#include <QGridLayout>
#include <QDebug>
#include <QtMath>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    setFixedSize(320, 400);
    setWindowTitle("Calculator");

    QFont font("Dune Rise", 14, QFont::Normal);
    QApplication::setFont(font);

    QColor backgroundColor("#1a2031");
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, backgroundColor);
    setPalette(palette);
    setAutoFillBackground(true);

    display = new QLineEdit(this);
    display->setGeometry(0, 0, 320, 100);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setText("");

    QString buttonLabels[] = {
        "+/-", "0", ".", "=",
        "1", "2", "3", "+",
        "4", "5", "6", "-",
        "7", "8", "9", "*",
        "1/x", "x^2", "sqrt", "/"
    };

    for (int i = 0; i < 20; ++i) {
        buttons[i] = createButton(buttonLabels[i], font, i);
    }

    buttonDelete = new QPushButton("<", this);
    buttonDelete->setFont(font);
    buttonDelete->setGeometry(240, 100, 80, 50);
    connect(buttonDelete, &QPushButton::clicked, this, &Calculator::handleDelete);

    buttonClear = new QPushButton("CE", this);
    buttonClear->setFont(font);
    buttonClear->setGeometry(160, 100, 80, 50);
    connect(buttonClear, &QPushButton::clicked, this, &Calculator::handleClear);
}

Calculator::~Calculator() {}

QPushButton* Calculator::createButton(const QString &text, const QFont &font, int index, int buttonWidth, int buttonHeight) {
    QPushButton *button = new QPushButton(text, this);
    button->setFont(font);
    button->setGeometry(positions[index][0], positions[index][1], buttonWidth, buttonHeight);

    connect(button, &QPushButton::clicked, this, [this, text]() {
        onButtonClicked(text);
    });

    return button;
}

double Calculator::evaluateExpression(const QString &expression) {
    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);
    if (result.isNumber()) {
        return result.toNumber();
    }
    return 0;
}

void Calculator::onButtonClicked(const QString &text) {
    if (text == "=") {
        QString expression = display->text();
        double result = evaluateExpression(expression);
        display->setText(QString::number(result));
    } else if (text == "1/x") {
        double value = display->text().toDouble();
        display->setText(value != 0 ? QString::number(1 / value) : "Error");
    } else if (text == "x^2") {
        double value = display->text().toDouble();
        display->setText(QString::number(qPow(value, 2)));
    } else if (text == "sqrt") {
        double value = display->text().toDouble();
        display->setText(value >= 0 ? QString::number(qSqrt(value)) : "Error");
    } else if (text == "+/-") {
        double value = display->text().toDouble();
        display->setText(QString::number(-value));
    } else {
        display->setText(display->text() + text);
    }
}

void Calculator::handleDelete() {
    QString currentText = display->text();
    currentText.chop(1);
    display->setText(currentText);
}

void Calculator::handleClear() {
    display->clear();
}
