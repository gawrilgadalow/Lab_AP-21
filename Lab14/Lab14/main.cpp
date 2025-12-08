#include <iostream>
#include "ResistorList.h"
using namespace std;

int main() {
    ResistorList list;

    list.pushBack(Resistor(1000, 0.25, 5));
    list.pushBack(Resistor(470, 0.5, 1));
    list.pushFront(Resistor(10, 2.0, 2));

    cout << "Pochatkovyi spysok:\n";
    list.print();

    cout << "\nVstavka pislia index 1:\n";
    Resistor r;
    r.input();
    list.insertAfter(1, r);
    list.print();

    cout << "\nVydalennia pershoho elementa:\n";
    list.popFront();
    list.print();

    cout << "\nVydalennia ostannioho elementa:\n";
    list.popBack();
    list.print();

    cout << "\nVydalennia rezystora z oporom 1000 Ohm:\n";
    list.removeByResistance(1000);
    list.print();

    return 0;
}
