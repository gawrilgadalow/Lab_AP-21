#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>

class Resistor {
private:
    double resistance;
    double maxPower;
    double accuracy;

public:
    // Конструктори
    Resistor();
    Resistor(double r, double p, double a);

    // Методи
    void input();
    void print() const;

    void setResistance(double r);
    void setMaxPower(double p);
    void setAccuracy(double a);

    double getResistance() const { return resistance; }
    double getMaxPower() const { return maxPower; }
    double getAccuracy() const { return accuracy; }
};

#endif
