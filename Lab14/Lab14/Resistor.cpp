#include "Resistor.h"
#include <iostream>

using namespace std;

// Конструктор за замовчуванням
Resistor::Resistor() {
    resistance = 1.0;
    maxPower = 0.25;
    accuracy = 5.0;
}

// Конструктор з параметрами
Resistor::Resistor(double r, double p, double a) {
    setResistance(r);
    setMaxPower(p);
    setAccuracy(a);
}

void Resistor::setResistance(double r) {
    if (r > 0) resistance = r;
    else {
        resistance = 1.0;
        cout << "Invalid resistance, set to 1 Ohm\n";
    }
}

void Resistor::setMaxPower(double p) {
    if (p > 0) maxPower = p;
    else {
        maxPower = 0.25;
        cout << "Invalid power, set to 0.25W\n";
    }
}

void Resistor::setAccuracy(double a) {
    if (a > 0 && a <= 20) accuracy = a;
    else {
        accuracy = 5.0;
        cout << "Invalid accuracy, set to 5%\n";
    }
}

void Resistor::input() {
    cout << "Enter resistance: ";
    cin >> resistance;

    cout << "Enter max power: ";
    cin >> maxPower;

    cout << "Enter accuracy (%): ";
    cin >> accuracy;
}

void Resistor::print() const {
    cout << "Resistor: "
        << resistance << " Ohm, "
        << maxPower << " W, "
        << accuracy << "% accuracy\n";
}
