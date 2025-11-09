#include "Powerbank.h"
#include <iostream>

Powerbank::Powerbank(const std::string& n, double p, double c, int ports, bool fast)
    : PowerSource(n, p, c), usbPorts(ports), fastCharge(fast) {
}

Powerbank::~Powerbank() {}

void Powerbank::input() {
    PowerSource::input();
    std::cout << "Kilkilkist USB portiv: ";
    std::cin >> usbPorts;
    std::cout << "Pidtrymka shvydkoi zaryadky (1 - tak / 0 - ni): ";
    std::cin >> fastCharge;
    std::cin.ignore();
}

void Powerbank::display() const {
    PowerSource::display();
    std::cout << "USB porty: " << usbPorts
        << "\nShvydka zaryadka: " << (fastCharge ? "Tak" : "Ni") << "\n";
}
