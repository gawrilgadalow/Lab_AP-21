#include "PowerSource.h"

PowerSource::PowerSource(const string& n, double p, double c)
    : name(n), power(p), capacity(c) {
}

PowerSource::~PowerSource() {}

void PowerSource::input() {
    cout << "Vvedit nazvu dzherela: ";
    getline(cin, name);
    cout << "Vvedit potuzhnist (W): ";
    cin >> power;
    cout << "Vvedit yemnist (Wh): ";
    cin >> capacity;
    cin.ignore();
}

void PowerSource::display() const {
    cout << "Dzherelo: " << name
        << "\nPotuzhnist: " << power << " W"
        << "\nYemnist: " << capacity << " Wh\n";
}
