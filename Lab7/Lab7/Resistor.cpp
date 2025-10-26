#include "resistor.h"
#include <iomanip>
#include <cmath>

ResistorManager::ResistorManager() {
    cout << "ResistorManager created.\n";
}

ResistorManager::~ResistorManager() {
    cout << "ResistorManager destroyed.\n";
}

void ResistorManager::addResistor(const ResistorData& rd) {
    ResistorData temp = rd;
    if (!validateAndCorrect(temp)) cout << "Invalid values corrected.\n";
    resistors.push_back(temp);
}

void ResistorManager::inputOne() {
    ResistorData rd;
    cout << "Enter label: "; cin >> rd.label;
    cout << "Enter resistance (Ohm): "; cin >> rd.resistance;
    cout << "Enter max power (W): "; cin >> rd.maxPower;
    cout << "Enter accuracy class (%): "; cin >> rd.accuracyClass;
    if (!validateAndCorrect(rd)) cout << "Incorrect values replaced by defaults.\n";
    resistors.push_back(rd);
}

void ResistorManager::displayAll() const {
    cout << "\n--- All resistors ---\n";
    if (resistors.empty()) { cout << "No entries.\n"; return; }
    cout << left << setw(10) << "Index" << setw(12) << "Label" << setw(12)
        << "Resistance" << setw(12) << "Power" << setw(12) << "Accuracy" << endl;
    for (size_t i = 0; i < resistors.size(); ++i) {
        cout << setw(10) << i
            << setw(12) << resistors[i].label
            << setw(12) << resistors[i].resistance
            << setw(12) << resistors[i].maxPower
            << setw(12) << resistors[i].accuracyClass << '\n';
    }
}

void ResistorManager::findByResistance(double target) const {
    bool found = false;
    for (size_t i = 0; i < resistors.size(); ++i) {
        if (fabs(resistors[i].resistance - target) < 1e-6) {
            printEntry(i);
            found = true;
        }
    }
    if (!found) cout << "No resistor with given resistance.\n";
}

void ResistorManager::removeAt(size_t index) {
    if (index < resistors.size()) {
        resistors.erase(resistors.begin() + index);
        cout << "Resistor removed.\n";
    }
    else {
        cout << "Invalid index.\n";
    }
}

void ResistorManager::clearAll() {
    resistors.clear();
    cout << "All data cleared.\n";
}

size_t ResistorManager::size() const { return resistors.size(); }

bool ResistorManager::validateAndCorrect(ResistorData& rd) const {
    bool ok = true;
    if (rd.resistance <= 0) { rd.resistance = 1.0; ok = false; }
    if (rd.maxPower <= 0) { rd.maxPower = 0.25; ok = false; }
    if (rd.accuracyClass <= 0 || rd.accuracyClass > 20) { rd.accuracyClass = 5.0; ok = false; }
    if (rd.label.empty()) rd.label = "unnamed";
    return ok;
}

void ResistorManager::printEntry(size_t i) const {
    cout << "Index " << i << " | Label: " << resistors[i].label
        << " | R = " << resistors[i].resistance << " Ohm"
        << " | P = " << resistors[i].maxPower << " W"
        << " | Acc = " << resistors[i].accuracyClass << " %\n";
}
