#include "ResistorList.h"
#include <iostream>
using namespace std;

ResistorList::ResistorList() : head(nullptr) {}

ResistorList::~ResistorList() {
    clear();
}

bool ResistorList::isEmpty() const {
    return head == nullptr;
}

void ResistorList::pushFront(const Resistor& r) {
    head = new Node(r, head);
}

void ResistorList::pushBack(const Resistor& r) {
    Node* node = new Node(r);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = node;
}

bool ResistorList::insertAfter(int index, const Resistor& r) {
    if (index < 0) return false;
    Node* cur = head;
    int i = 0;
    while (cur && i < index) {
        cur = cur->next;
        i++;
    }
    if (!cur) return false;

    cur->next = new Node(r, cur->next);
    return true;
}

bool ResistorList::popFront() {
    if (!head) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool ResistorList::popBack() {
    if (!head) return false;
    if (!head->next) {
        delete head;
        head = nullptr;
        return true;
    }
    Node* cur = head;
    while (cur->next->next)
        cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
    return true;
}

bool ResistorList::removeByResistance(double resistance) {
    if (!head) return false;

    if (head->data.getResistance() == resistance) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* cur = head;
    while (cur->next && cur->next->data.getResistance() != resistance)
        cur = cur->next;

    if (!cur->next) return false;

    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
    return true;
}

void ResistorList::clear() {
    while (head)
        popFront();
}

void ResistorList::print() const {
    if (!head) {
        cout << "Spysok pustyi.\n";
        return;
    }
    Node* cur = head;
    int index = 0;
    while (cur) {
        cout << index << ") ";
        cur->data.print();
        cur = cur->next;
        index++;
    }
}
