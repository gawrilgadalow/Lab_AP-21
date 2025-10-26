#include "resistor.h"

int main() {
    ResistorManager mgr;
    ResistorManager::ResistorData r1 = { 1000, 0.5, 1, "R1000" };
    ResistorManager::ResistorData r2 = { 220, 0.25, 5, "R220" };
    ResistorManager::ResistorData r3 = { -5, 0, 50, "bad" };

    mgr.addResistor(r1);
    mgr.addResistor(r2);
    mgr.addResistor(r3);

    mgr.displayAll();
    mgr.findByResistance(1000.0);

    mgr.inputOne();
    mgr.displayAll();

    mgr.removeAt(1);
    mgr.displayAll();

    mgr.clearAll();
    mgr.displayAll();

    return 0;
}
