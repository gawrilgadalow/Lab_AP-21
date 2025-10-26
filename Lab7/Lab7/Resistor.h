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
    vector<ResistorData> resistors;

public:
    ResistorManager();
    ~ResistorManager();

    void addResistor(const ResistorData& rd);
    void inputOne();
    void displayAll() const;
    void findByResistance(double target) const;
    void removeAt(size_t index);
    void clearAll();
    size_t size() const;

private:
    bool validateAndCorrect(ResistorData& rd) const;
    void printEntry(size_t i) const;
};
#endif
