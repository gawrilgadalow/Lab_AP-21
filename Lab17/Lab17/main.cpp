#include <iostream>
#include <string>

#include "Templates.h"
#include "Resistor.h"

int main() {
    // ØÀÁËÎÍ ÔÓÍÊÖ²¯
    std::cout << "Max value: " << maxValue(10, 25) << "\n\n";

    // ÇÀÃÀËÜÍÈÉ ØÀÁËÎÍ
    Resistor<int, double, int> r1(1000, 0.5, 5);
    r1.print();

    // ×ÀÑÒÊÎÂÀ ÑÏÅÖ²ÀË²ÇÀÖ²ß
    Resistor<int, double, std::string> r2(220, 0.25, "±10%");
    r2.print();

    // ÏÎÂÍÀ ÑÏÅÖ²ÀË²ÇÀÖ²ß
    Resistor<double, double, double> r3(470.0, 0.25, 1.0);
    r3.print();

    return 0;
}
