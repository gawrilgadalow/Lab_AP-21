#include "Header1.h"

// ����������� �� �������������
Resistor::Resistor() {
    resistance = 1.0;
    maxPower = 0.25;
    accuracyClass = 5.0;
}

// ����������� � �����������
Resistor::Resistor(double r, double p, double a) {
    setResistance(r);
    setMaxPower(p);
    setAccuracyClass(a);
}

// ����������
Resistor::~Resistor() {
    cout << "Rezystor z oporom " << resistance << " Om znyshcheno\n";
}

// �������� ����� � ���������
void Resistor::input() {
    double r, p, a;
    cout << "Vvedit' nominalnyj opir (Om): ";
    cin >> r;
    setResistance(r);

    cout << "Vvedit' maksymal'nu potuzhnist' (Wt): ";
    cin >> p;
    setMaxPower(p);

    cout << "Vvedit' klas tochnosti (%): ";
    cin >> a;
    setAccuracyClass(a);
}

// ���� ����������
void Resistor::display() const {
    cout << "\nRezystor:";
    cout << "\n  Opir: " << resistance << " Om";
    cout << "\n  Maksymalna potuzhnist': " << maxPower << " Wt";
    cout << "\n  Klas tochnosti: " << accuracyClass << " %\n";
}

// �������
void Resistor::setResistance(double r) {
    if (r > 0) resistance = r;
    else {
        resistance = 1.0;
        cout << "Nekorektnyj opir! Vstanovleno 1 Om\n";
    }
}

void Resistor::setMaxPower(double p) {
    if (p > 0) maxPower = p;
    else {
        maxPower = 0.25;
        cout << "Nekorektna potuzhnist'! Vstanovleno 0.25 Wt\n";
    }
}

void Resistor::setAccuracyClass(double a) {
    if (a > 0 && a <= 20) accuracyClass = a;
    else {
        accuracyClass = 5.0;
        cout << "Nekorektnyj klas tochnosti! Vstanovleno 5%\n";
    }
}

// �������
double Resistor::getResistance() const { return resistance; }
double Resistor::getMaxPower() const { return maxPower; }
double Resistor::getAccuracyClass() const { return accuracyClass; }
