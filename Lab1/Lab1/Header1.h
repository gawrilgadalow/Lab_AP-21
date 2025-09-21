#pragma once
#ifndef HEADER1_H
#define HEADER1_H

#include <iostream>
using namespace std;

class Resistor {
private:
    double resistance;
    double maxPower;
    double accuracyClass;

public:
    Resistor();  // ����������� �� �������������
    Resistor(double r, double p, double a);  // ����������� � �����������
    ~Resistor();  // ����������

    void input();
    void display() const;

    void setResistance(double r);
    void setMaxPower(double p);
    void setAccuracyClass(double a);

    double getResistance() const;
    double getMaxPower() const;
    double getAccuracyClass() const;
};

#endif

