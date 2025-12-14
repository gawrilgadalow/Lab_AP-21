#include "Powerbank.h"
#include <stdexcept>

Powerbank::Powerbank(const std::string& n,
    double p,
    double c,
    int ports,
    bool fast)
    : PowerSource(n, p),
    capacityWh(c),
    usbPorts(ports),
    fastCharge(fast) {
}

void Powerbank::load(std::istream& in) {
    in >> name >> power >> capacityWh >> usbPorts >> fastCharge;
    if (!in || power < 0 || capacityWh < 0 || usbPorts < 0) {
        throw std::runtime_error("Invalid Powerbank input");
    }
}

void Powerbank::print(std::ostream& out) const {
    out << "[Powerbank]\n";
    PowerSource::print(out);
    out << "Capacity: " << capacityWh << " Wh\n"
        << "USB ports: " << usbPorts << "\n"
        << "Fast charge: " << (fastCharge ? "Yes" : "No") << "\n";
}

void Powerbank::saveToFile(std::ostream& out) const {
    out << typeCode() << " "
        << name << " "
        << power << " "
        << capacityWh << " "
        << usbPorts << " "
        << fastCharge << "\n";
}

void Powerbank::loadFromFile(std::istream& in) {
    in >> name >> power >> capacityWh >> usbPorts >> fastCharge;
    if (!in) throw std::runtime_error("File read error (Powerbank)");
}
