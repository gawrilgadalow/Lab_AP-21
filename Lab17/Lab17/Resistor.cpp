#include "Resistor.h"

Resistor::Resistor(double r) : resistance(r) {}

double Resistor::getResistance() const {
    return resistance;
}

bool Resistor::operator<(const Resistor& other) const {
    return resistance < other.resistance;
}

ostream& operator<<(ostream& os, const Resistor& r) {
    os << r.resistance << " Ohm";
    return os;
}
