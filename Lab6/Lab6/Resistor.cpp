#include "resistor.h"
#include <cmath>
#include <iomanip>

ResistorManager::ResistorManager() : count(0) {
    for (size_t i = 0; i < SIZE; ++i) {
        resistors[i].resistance = 1.0;
        resistors[i].maxPower = 0.25;
        resistors[i].accuracyClass = 5.0;
        resistors[i].label = "empty";
    }
    cout << "ResistorManager created. Capacity = " << SIZE << endl;
}

ResistorManager::~ResistorManager() {
    cout << "ResistorManager destroyed. Stored entries: " << count << endl;
}

bool ResistorManager::addResistor(const ResistorData& rd) {
    if (count >= SIZE) {
        cout << "Cannot add: array is full.\n";
        return false;
    }
    ResistorData temp = rd;
    if (!validateAndCorrect(temp))
        cout << "Some invalid values corrected.\n";

    resistors[count++] = temp;
    return true;
}

void ResistorManager::inputOne() {
    if (count >= SIZE) {
        cout << "Array is full.\n";
        return;
    }

    ResistorData rd;
    cout << "\nEnter label: ";
    cin >> rd.label;
    cout << "Enter resistance (Ohm): ";
    cin >> rd.resistance;
    cout << "Enter max power (W): ";
    cin >> rd.maxPower;
    cout << "Enter accuracy class (%): ";
    cin >> rd.accuracyClass;

    if (!validateAndCorrect(rd))
        cout << "Incorrect values were replaced by defaults.\n";

    resistors[count++] = rd;
}

void ResistorManager::displayAll() const {
    cout << "\n--- All resistors (" << count << ") ---\n";
    if (count == 0) {
        cout << "No entries.\n";
        return;
    }
    cout << left << setw(8) << "Index" << setw(12) << "Label" << setw(14)
        << "Resistance" << setw(12) << "Power" << setw(12) << "Accuracy" << endl;

    for (size_t i = 0; i < count; ++i) {
        cout << setw(8) << i
            << setw(12) << resistors[i].label
            << setw(14) << resistors[i].resistance
            << setw(12) << resistors[i].maxPower
            << setw(12) << resistors[i].accuracyClass << '\n';
    }
}

void ResistorManager::findByResistance(double target) const {
    cout << "\nSearching for resistance ~ " << target << " Ohm\n";
    bool found = false;
    for (size_t i = 0; i < count; ++i) {
        if (fabs(resistors[i].resistance - target) < 1e-6) {
            printEntry(i);
            found = true;
        }
    }
    if (!found) cout << "No resistor found.\n";
}

void ResistorManager::displayByMinPower(double minPower) const {
    cout << "\nResistors with power >= " << minPower << " W:\n";
    bool found = false;
    for (size_t i = 0; i < count; ++i) {
        if (resistors[i].maxPower >= minPower) {
            printEntry(i);
            found = true;
        }
    }
    if (!found) cout << "No resistors found.\n";
}

bool ResistorManager::setAt(size_t index, const ResistorData& rd) {
    if (index >= count) {
        cout << "Invalid index.\n";
        return false;
    }
    ResistorData temp = rd;
    if (!validateAndCorrect(temp))
        cout << "Values corrected.\n";

    resistors[index] = temp;
    return true;
}

size_t ResistorManager::size() const {
    return count;
}

bool ResistorManager::validateAndCorrect(ResistorData& rd) const {
    bool ok = true;
    if (rd.resistance <= 0) {
        rd.resistance = 1.0;
        ok = false;
    }
    if (rd.maxPower <= 0) {
        rd.maxPower = 0.25;
        ok = false;
    }
    if (rd.accuracyClass <= 0 || rd.accuracyClass > 20) {
        rd.accuracyClass = 5.0;
        ok = false;
    }
    if (rd.label.empty())
        rd.label = "unnamed";
    return ok;
}

void ResistorManager::printEntry(size_t i) const {
    cout << "Index " << i << " | Label: " << resistors[i].label
        << " | R = " << resistors[i].resistance << " Ohm"
        << " | P = " << resistors[i].maxPower << " W"
        << " | Acc = " << resistors[i].accuracyClass << " %\n";
}
