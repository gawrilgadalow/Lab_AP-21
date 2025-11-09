#include "Generator.h"
#include <iostream>

Generator::Generator(const std::string& n, double p, double c,
    const std::string& fuel, double cons)
    : PowerSource(n, p, c), fuelType(fuel), fuelConsumption(cons) {
}

Generator::~Generator() {}

void Generator::input() {
    PowerSource::input();
    std::cout << "Typ palyva: ";
    std::getline(std::cin, fuelType);
    std::cout << "Vytraty palyva (l/h): ";
    std::cin >> fuelConsumption;
    std::cin.ignore();
}

void Generator::display() const {
    PowerSource::display();
    std::cout << "Typ palyva: " << fuelType
        << "\nVytraty palyva: " << fuelConsumption << " l/h\n";
}
