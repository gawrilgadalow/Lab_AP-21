#include "resistor.h"

int main() {
    ResistorManager mgr;

    // Додаємо кілька резисторів
    ResistorManager::ResistorData r1 = { 1000, 0.5, 1, "R1000" };
    ResistorManager::ResistorData r2 = { 220, 0.25, 5, "R220" };
    ResistorManager::ResistorData r3 = { -5, 0, 50, "bad" }; // некоректні значення

    mgr.addResistor(r1);
    mgr.addResistor(r2);
    mgr.addResistor(r3);

    mgr.displayAll();

    // Пошук за опором
    mgr.findByResistance(1000.0);

    // Фільтрація за потужністю
    mgr.displayByMinPower(0.3);

    // Введення вручну
    mgr.inputOne();
    mgr.displayAll();

    return 0;
}
