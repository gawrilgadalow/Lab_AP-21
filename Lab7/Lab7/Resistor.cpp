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

// 🔥 ВСТАВКА ЕЛЕМЕНТА В ДОВІЛЬНУ ПОЗИЦІЮ
void ResistorManager::insertAt(size_t index, const ResistorData& rd) {
    ResistorData temp = rd;
    validateAndCorrect(temp);

    if (index > resistors.size()) {
        cout << "Index out of range. Element inserted at the end.\n";
        resistors.push_back(temp);
    }
    else {
        resistors.insert(resistors.begin() + index, temp);
    }

    cout << "Inserted at position " << index << endl;
}

// 🔥 ОБМІН ЕЛЕМЕНТІВ У ВЕКТОРІ
void ResistorManager::swapPositions(size_t index1, size_t index2) {
    if (index1 >= resistors.size() || index2 >= resistors.size()) {
        cout << "Invalid indices. Swap aborted.\n";
        return;
    }

    swap(resistors[index1], resistors[index2]);
    cout << "Swapped objects at positions " << index1 << " and " << index2 << endl;
}

void ResistorManager::inputOne() {
    ResistorData rd;
    cout << "Enter label: "; cin >> rd.label;
    cout << "Enter resistance (Ohm): "; cin >> rd.resistance;
    cout << "Enter max power (W): "; cin >> rd.maxPower;
    cout << "Enter accuracy class (%): "; cin >> rd.accuracyClass;

    validateAndCorrect(rd);
    resistors.push_back(rd);
}

void ResistorManager::displayAll() const {
    if (resistors.empty()) {
        cout << "No resistors stored.\n";
        return;
    }

    cout << "\n--- Resistor list ---\n";
    cout << left << setw(10) << "Index"
        << setw(12) << "Label"
        << setw(12) << "R(Ohm)"
        << setw(12) << "Power(W)"
        << setw(12) << "Accuracy(%)" << endl;

    for (size_t i = 0; i < resistors.size(); ++i) {
        cout << setw(10) << i
            << setw(12) << resistors[i].label
            << setw(12) << resistors[i].resistance
            << setw(12) << resistors[i].maxPower
            << setw(12) << resistors[i].accuracyClass << endl;
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

    if (!found) cout << "No resistor with this resistance.\n";
}

size_t ResistorManager::size() const { return resistors.size(); }

void ResistorManager::removeAt(size_t index) {
    if (index < resistors.size()) {
        resistors.erase(resistors.begin() + index);
        cout << "Removed.\n";
    }
    else cout << "Invalid index.\n";
}

void ResistorManager::clearAll() {
    resistors.clear();
    cout << "All entries cleared.\n";
}

bool ResistorManager::validateAndCorrect(ResistorData& rd) const {
    bool ok = true;
    if (rd.resistance <= 0) { rd.resistance = 1.0; ok = false; }
    if (rd.maxPower <= 0) { rd.maxPower = 0.25; ok = false; }
    if (rd.accuracyClass <= 0 || rd.accuracyClass > 20) { rd.accuracyClass = 5.0; ok = false; }
    if (rd.label.empty()) rd.label = "unnamed";
    return ok;
}

void ResistorManager::printEntry(size_t i) const {
    cout << "Index " << i
        << " | Label: " << resistors[i].label
        << " | R=" << resistors[i].resistance
        << " | P=" << resistors[i].maxPower
        << " | Acc=" << resistors[i].accuracyClass << "%\n";
}
