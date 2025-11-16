#include "Powerbank.h"

Powerbank::Powerbank(const string& n, double p, double c, int ports, bool fast)
    : PowerSource(n, p, c), usbPorts(ports), fastCharge(fast) {}

Powerbank::~Powerbank() {}

void Powerbank::input() {
    PowerSource::input();
    cout << "Kilkilkist USB portiv: ";
    cin >> usbPorts;
    cout << "Pidtrymka shvydkoi zaryadky (1-tak 0-ni): ";
    cin >> fastCharge;
    cin.ignore();
}

void Powerbank::display() const {
    PowerSource::display();
    cout << "USB porty: " << usbPorts
         << "\nShvydka zaryadka: " << (fastCharge ? "Tak" : "Ni") << "\n";
}
