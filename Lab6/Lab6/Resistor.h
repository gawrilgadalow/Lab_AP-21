#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <array>
#include <string>
using namespace std;

class ResistorManager {
public:
    struct ResistorData {
        double resistance;
        double maxPower;
        double accuracyClass;
        string label;
    };

    static const size_t SIZE = 5; // розмір статичного масиву

private:
    array<ResistorData, SIZE> resistors;
    size_t count;

public:
    ResistorManager(); // конструктор за замовчуванням
    ~ResistorManager(); // деструктор

    bool addResistor(const ResistorData& rd);
    void inputOne();
    void displayAll() const;
    void findByResistance(double target) const;
    void displayByMinPower(double minPower) const;
    bool setAt(size_t index, const ResistorData& rd);
    size_t size() const;

private:
    bool validateAndCorrect(ResistorData& rd) const;
    void printEntry(size_t i) const;
};

#endif
