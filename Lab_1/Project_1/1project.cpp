#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Resistor {
private:
    double resistance;     // Nominalnyj opir (Om)
    double maxPower;       // Maksymalna potuzhnist' rosiyannya (Wt)
    double accuracyClass;  // Klas tochnosti (%)

public:
    // 1. Konstruktor za zamovchuvannyam
    Resistor() {
        resistance = 1.0;
        maxPower = 0.25;
        accuracyClass = 5.0;
        cout << "Stvoreno rezystor za zamovchuvannyam\n";
    }

    // 2. Konstruktor z parametramy
    Resistor(double r, double p, double a) {
        setResistance(r);
        setMaxPower(p);
        setAccuracyClass(a);
        cout << "Stvoreno rezystor z parametramy\n";
    }

    // 3. Destruktor
    ~Resistor() {
        cout << "Rezystor z oporom " << resistance << " Om znyshcheno\n";
    }

    // Metody vvedennya danykh
    void input() {
        double r, p, a;
        cout << "\nVvedit' nominalnyj opir (Om): ";
        cin >> r;
        setResistance(r);

        cout << "Vvedit' maksymal'nu potuzhnist' (Wt): ";
        cin >> p;
        setMaxPower(p);

        cout << "Vvedit' klas tochnosti (%): ";
        cin >> a;
        setAccuracyClass(a);
    }

    // Metod vyvedennya danykh
    void display() const {
        cout << "\nRezystor:";
        cout << "\n  Opir: " << resistance << " Om";
        cout << "\n  Maksymalna potuzhnist': " << maxPower << " Wt";
        cout << "\n  Klas tochnosti: " << accuracyClass << " %\n";
    }

    // Setery z perevirkoyu
    void setResistance(double r) {
        if (r > 0) resistance = r;
        else {
            resistance = 1.0;
            cout << "Nekorektnyj opir! Vstanovleno 1 Om\n";
        }
    }

    void setMaxPower(double p) {
        if (p > 0) maxPower = p;
        else {
            maxPower = 0.25;
            cout << "Nekorektna potuzhnist'! Vstanovleno 0.25 Wt\n";
        }
    }

    void setAccuracyClass(double a) {
        if (a > 0 && a <= 20) accuracyClass = a;
        else {
            accuracyClass = 5.0;
            cout << "Nekorektnyj klas tochnosti! Vstanovleno 5%\n";
        }
    }

    // Getery
    double getResistance() const { return resistance; }
    double getMaxPower() const { return maxPower; }
    double getAccuracyClass() const { return accuracyClass; }
};

int main() {
    // 1. Stvorennya rezystora za zamovchuvannyam
    Resistor R1;
    R1.display();

    // 2. Stvorennya rezystora z parametramy
    Resistor R2(1000, 0.5, 1.0);
    R2.display();

    // 3. Vvedennya danykh korystuvachem
    Resistor R3;
    R3.input();
    R3.display();

    // 4. Zberezhennya kilkoh rezystoriv u vektor
    vector<Resistor> resistors;
    resistors.push_back(R1);
    resistors.push_back(R2);
    resistors.push_back(R3);

    // 5. Poshuk za kryteriyem: opir = 1000 Om
    cout << "\n=== Poshuk rezystoriv z oporom 1000 Om ===\n";
    bool found = false;
    for (const auto& r : resistors) {
        if (r.getResistance() == 1000) {
            r.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Rezystoriv z oporom 1000 Om ne znajdeno!\n";
    }

    return 0;
}
