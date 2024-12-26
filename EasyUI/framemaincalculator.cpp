#include "framemaincalculator.h"
#include "Calculator.h"
FrameMainCalculator::FrameMainCalculator(QWidget *parent) : QFrame(parent) {
    setGeometry(280, 20, 1000, 702);
    setStyleSheet("background-color: #16171b;");
    Calculator *x1 = new Calculator(this);
}
