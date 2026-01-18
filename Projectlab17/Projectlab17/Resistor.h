#pragma once
#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <string>


template <typename T1, typename T2, typename T3>
class Resistor {
public:
    T1 resistance;
    T2 power;
    T3 accuracy;

    Resistor(T1 r, T2 p, T3 a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "General template\n";
        std::cout << resistance << " Ohm, "
            << power << " W, "
            << accuracy << "\n\n";
    }
};


template <typename T1, typename T2>
class Resistor<T1, T2, std::string> {
public:
    T1 resistance;
    T2 power;
    std::string accuracy;

    Resistor(T1 r, T2 p, const std::string& a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "Partial specialization\n";
        std::cout << resistance << " Ohm, "
            << power << " W, "
            << accuracy << "\n\n";
    }
};

template <>
class Resistor<double, double, double> {
public:
    double resistance;
    double power;
    double accuracy;

    Resistor(double r, double p, double a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "FULL specialization\n";
        std::cout << resistance << " Ohm, "
            << power << " W, ±"
            << accuracy << "%\n\n";
    }
};

#endif
