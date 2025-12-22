#include <iostream>
#include "Resistor.h"
#include "Templates.h"

using namespace std;

int main() {
    int a = 10, b = 5;
    cout << "Min int: " << findMin(a, b) << endl;

    double x = 3.14, y = 2.71;
    cout << "Min double: " << findMin(x, y) << endl;

    Resistor r1(1000);
    Resistor r2(470);

    cout << "Resistor 1: " << r1 << endl;
    cout << "Resistor 2: " << r2 << endl;

    cout << "Min resistor: " << findMin(r1, r2) << endl;

    return 0;
}
