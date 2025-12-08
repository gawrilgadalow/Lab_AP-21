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
    if (!in) {
        throw std::runtime_error("Pomylka vvedennia dlia Powerbank");
    }
    if (power < 0 || capacityWh < 0 || usbPorts < 0) {
        throw std::runtime_error("Vidjemni znachennia u Powerbank");
    }
}

void Powerbank::print(std::ostream& out) const {
    out << "[Powerbank]\n";
    PowerSource::print(out);
    out << "Yemnist: " << capacityWh << " Wh\n"
        << "USB porty: " << usbPorts << "\n"
        << "Shvydka zaryadka: " << (fastCharge ? "Tak" : "Ni") << "\n";
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
    if (!in) {
        throw std::runtime_error("Nevdalyi chytannia Powerbank z failu");
    }
    if (power < 0 || capacityWh < 0 || usbPorts < 0) {
        throw std::runtime_error("Vidjemni znachennia u Powerbank (fail)");
    }
}
