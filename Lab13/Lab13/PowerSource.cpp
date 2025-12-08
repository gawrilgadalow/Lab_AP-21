#include "PowerSource.h"
#include <stdexcept>

PowerSource::PowerSource(const std::string& n, double p)
    : name(n), power(p) {
}

void PowerSource::load(std::istream& in) {
    in >> name >> power;
    if (!in) {
        throw std::runtime_error("Pomylka vvedennia dlia PowerSource");
    }
    if (power < 0) {
        throw std::runtime_error("Potuzhnist ne mozhe buty vidjemnoiu");
    }
}

void PowerSource::print(std::ostream& out) const {
    out << "Nazva: " << name << "\n"
        << "Potuzhnist: " << power << " W\n";
}
