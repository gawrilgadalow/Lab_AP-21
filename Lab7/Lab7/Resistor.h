#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <vector>
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

private:
    vector<ResistorData> resistors;   // внутрішній контейнер класу

public:
    ResistorManager();
    ~ResistorManager();

    void addResistor(const ResistorData& rd);      // додавання в кінець
    void insertAt(size_t index, const ResistorData& rd);  // 🔥 вставка у довільне місце
    void swapPositions(size_t index1, size_t index2);     // 🔥 обмін двох елементів

    void inputOne();
    void displayAll() const;

    void findByResistance(double target) const;

    size_t size() const;
    void removeAt(size_t index);
    void clearAll();

private:
    bool validateAndCorrect(ResistorData& rd) const;
    void printEntry(size_t i) const;
};

#endif
