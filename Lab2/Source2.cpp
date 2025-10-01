
#include <iostream>
#include <vector>
#include "Header1.h"
using namespace std;

int main() {
    Resistor R1;
    R1.display();

    Resistor R2(1000, 0.5, 1.0);
    R2.display();

    Resistor R3;
    R3.input();
    R3.display();

    vector<Resistor> resistors = { R1, R2, R3 };

    cout << "\n=== Poshuk rezystoriv z oporom 1000 Om ===\n";
    bool found = false;
    for (const auto& r : resistors) {
        if (r.getResistance() == 1000) {
            r.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Rezystoriv z oporom 1000 Om ne znajdeno!\n";
    }

    return 0;
}
