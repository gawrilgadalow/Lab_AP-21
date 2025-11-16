#include "Generator.h"

Generator::Generator(const string& n, double p, double c,
    const string& fuel, double cons)
    : PowerSource(n, p, c), fuelType(fuel), fuelConsumption(cons) {
}

Generator::~Generator() {}

void Generator::input() {
    PowerSource::input();
    cout << "Typ palyva: ";
    getline(cin, fuelType);
    cout << "Vytraty palyva (l/h): ";
    cin >> fuelConsumption;
    cin.ignore();
}

void Generator::display() const {
    PowerSource::display();
    cout << "Typ palyva: " << fuelType
        << "\nVytraty palyva: " << fuelConsumption << " l/h\n";
}
