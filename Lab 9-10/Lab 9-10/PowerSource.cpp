#include "PowerSource.h"

PowerSource::PowerSource(const std::string& n, double p, double c)
    : name(n), power(p), capacity(c) {
}

PowerSource::~PowerSource() {}

void PowerSource::input() {
    std::cout << "Vvedit nazvu dzherela zhivlennia: ";
    std::getline(std::cin, name);
    std::cout << "Vvedit potuzhnist (W): ";
    std::cin >> power;
    std::cout << "Vvedit yemnist (Wh): ";
    std::cin >> capacity;
    std::cin.ignore();
}

void PowerSource::display() const {
    std::cout << "Dzherelo: " << name
        << "\nPotuzhnist: " << power << " W"
        << "\nYemnist: " << capacity << " Wh\n";
}
