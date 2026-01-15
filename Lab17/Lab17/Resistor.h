#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>
#include <string>

/* =========================
   «¿√¿À‹Õ»… ÿ¿¡ÀŒÕ  À¿—”
   ========================= */
template <typename T1, typename T2, typename T3>
class Resistor {
protected:
    T1 resistance;
    T2 power;
    T3 accuracy;

public:
    Resistor(T1 r, T2 p, T3 a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "Resistor (general template)\n";
        std::cout << "R = " << resistance << " Ohm\n";
        std::cout << "P = " << power << " W\n";
        std::cout << "Accuracy = " << accuracy << "\n\n";
    }
};

/* =========================
   ◊¿—“ Œ¬¿ —œ≈÷≤¿À≤«¿÷≤ﬂ
   (accuracy = std::string)
   ========================= */
template <typename T1, typename T2>
class Resistor<T1, T2, std::string> {
private:
    T1 resistance;
    T2 power;
    std::string accuracy;

public:
    Resistor(T1 r, T2 p, const std::string& a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "Resistor (partial specialization)\n";
        std::cout << "R = " << resistance << " Ohm\n";
        std::cout << "P = " << power << " W\n";
        std::cout << "Accuracy = " << accuracy << "\n\n";
    }
};

/* =========================
   œŒ¬Õ¿ —œ≈÷≤¿À≤«¿÷≤ﬂ
   (double, double, double)
   ========================= */
template <>
class Resistor<double, double, double> {
private:
    double resistance;
    double power;
    double accuracy;

public:
    Resistor(double r, double p, double a)
        : resistance(r), power(p), accuracy(a) {
    }

    void print() const {
        std::cout << "Resistor (FULL specialization)\n";
        std::cout << "R = " << resistance << " Ohm\n";
        std::cout << "P = " << power << " W\n";
        std::cout << "Accuracy = ±" << accuracy << " %\n\n";
    }
};

#endif
