#include "Resistor.h"

int main() {
    Resistor R1;
    R1.display();

    Resistor R2(1000, 0.5, 1.0);
    R2.display();

    Resistor R3;
    R3.input();
    R3.display();

    cout << "\n=== Poshuk rezystora z oporom 1000 Om ===\n";
    if (R2.getResistance() == 1000) {
        R2.display();
    }
    else {
        cout << "Rezystoriv z oporom 1000 Om ne znajdeno!\n";
    }

    return 0;
}
