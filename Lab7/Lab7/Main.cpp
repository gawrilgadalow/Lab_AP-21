#include "resistor.h"

int main() {
    ResistorManager mgr;

    ResistorManager::ResistorData r1 = { 1000, 0.5, 1, "R1000" };
    ResistorManager::ResistorData r2 = { 220, 0.25, 5, "R220" };
    ResistorManager::ResistorData r3 = { 470, 0.25, 10, "R470" };
    ResistorManager::ResistorData r4 = { 330, 0.25, 2, "R330" };

    mgr.addResistor(r1);
    mgr.addResistor(r2);
    mgr.addResistor(r3);

    mgr.displayAll();

    cout << "\n--- insertAt(1, R330) ---\n";
    mgr.insertAt(1, r4);
    mgr.displayAll();

    cout << "\n--- swapPositions(0, 2) ---\n";
    mgr.swapPositions(0, 2);
    mgr.displayAll();

    return 0;
}
