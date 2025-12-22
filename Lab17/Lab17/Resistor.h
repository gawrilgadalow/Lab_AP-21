#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
using namespace std;

class Resistor {
private:
    double resistance;

public:
    Resistor(double r = 0);

    double getResistance() const;

    bool operator<(const Resistor& other) const;
    friend ostream& operator<<(ostream& os, const Resistor& r);
};

#endif
#pragma once
