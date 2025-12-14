#include "PowerSource.h"
#include <stdexcept>

PowerSource::PowerSource(const std::string& n, double p)
    : name(n), power(p) {
}

void PowerSource::load(std::istream& in) {
    in >> name >> power;
    if (!in || power < 0) {
        throw std::runtime_error("Invalid PowerSource input");
    }
}

void PowerSource::print(std::ostream& out) const {
    out << "Name: " << name << "\n"
        << "Power: " << power << " W\n";
}
