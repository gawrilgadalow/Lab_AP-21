#ifndef RESISTORLIST_H
#define RESISTORLIST_H

#include "Resistor.h"

class ResistorList {
private:
    struct Node {
        Resistor data;
        Node* next;
        Node(const Resistor& r, Node* n = nullptr)
            : data(r), next(n) {
        }
    };

    Node* head;

public:
    ResistorList();
    ~ResistorList();

    bool isEmpty() const;

    void pushFront(const Resistor& r);
    void pushBack(const Resistor& r);
    bool insertAfter(int index, const Resistor& r);

    bool popFront();
    bool popBack();
    bool removeByResistance(double resistance);

    void clear();
    void print() const;
};

#endif // RESISTORLIST_H
