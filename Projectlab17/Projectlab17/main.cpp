#include <iostream>

#include "Templates.h"
#include "Resistor.h"

int main() {

    std::cout << "Max value: " << maxValue(10, 25) << "\n\n";


    Resistor<int, double, int> r1(1000, 0.5, 5);
    r1.print();

    Resistor<int, double, std::string> r2(220, 0.25, "±10%");
    r2.print();


    Resistor<double, double, double> r3(470.0, 0.25, 1.0);
    r3.print();

    return 0;
}
