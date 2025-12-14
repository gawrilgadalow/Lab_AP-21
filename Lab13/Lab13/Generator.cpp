#include "Generator.h"
#include <stdexcept>

Generator::Generator(const std::string& n,
    double p,
    const std::string& fuel,
    double cons)
    : PowerSource(n, p),
    fuelType(fuel),
    fuelConsumption(cons) {
}

void Generator::load(std::istream& in) {
    in >> name >> power >> fuelType >> fuelConsumption;
    if (!in || power < 0 || fuelConsumption < 0) {
        throw std::runtime_error("Invalid Generator input");
    }
}

void Generator::print(std::ostream& out) const {
    out << "[Generator]\n";
    PowerSource::print(out);
    out << "Fuel type: " << fuelType << "\n"
        << "Fuel consumption: " << fuelConsumption << " l/h\n";
}

void Generator::saveToFile(std::ostream& out) const {
    out << typeCode() << " "
        << name << " "
        << power << " "
        << fuelType << " "
        << fuelConsumption << "\n";
}

void Generator::loadFromFile(std::istream& in) {
    in >> name >> power >> fuelType >> fuelConsumption;
    if (!in) throw std::runtime_error("File read error (Generator)");
}
