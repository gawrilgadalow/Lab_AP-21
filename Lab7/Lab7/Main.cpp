#include "Resistor.h"
using namespace std;

int main() {
    int n;
    cout << "Vvedit' kilkist' rezystoriv: ";
    cin >> n;

    Resistor* arr = new Resistor[n];

    for (int i = 0; i < n; i++) {
        cout << "\nRezystor #" << i + 1 << endl;
        arr[i].input();
    }

    cout << "\n=== Vvedeni rezystory ===\n";
    for (int i = 0; i < n; i++) {
        arr[i].display();
    }

    cout << "\n=== Poshuk rezystora z oporom 1000 Om ===\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].getResistance() == 1000) {
            arr[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "Rezystoriv z oporom 1000 Om ne znajdeno!\n";
    }

    delete[] arr;
    return 0;
}

