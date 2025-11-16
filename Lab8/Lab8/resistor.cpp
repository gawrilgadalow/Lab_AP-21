#include "resistor.h"
#include <iomanip>
#include <limits>

Rezystor::Rezystor()
    : opir(1.0), potuzhnist(0.25), tochnist(5.0), nazva("R_default")
{
    std::cout << "[konstr] Rezystor stvorenyi za zamovchuvannyam\n";
}

Rezystor::Rezystor(double r, double p, double acc, const std::string& name)
    : opir(1.0), potuzhnist(0.25), tochnist(5.0), nazva("R_default")
{
    vstanovytyOpir(r);
    vstanovytyPotuzhnist(p);
    vstanovytyTochnist(acc);
    vstanovytyNazvu(name);
    std::cout << "[konstr] Rezystor stvorenyi z parametramy\n";
}

Rezystor::~Rezystor() {
    std::cout << "[destr] Rezystor '" << nazva << "' znyscheno\n";
}

void Rezystor::vyvesty() const {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Rezystor '" << nazva << "': "
        << "R=" << opir << " Om, "
        << "Pmax=" << potuzhnist << " W, "
        << "Tochn=" << tochnist << " %\n";
}

void Rezystor::vvodyty() {
    double r, p, acc;
    std::string name;

    std::cout << "Vvedit nazvu: ";
    std::cin >> name;
    std::cout << "Vvedit opir (Om): ";
    std::cin >> r;
    std::cout << "Vvedit potuzhnist (W): ";
    std::cin >> p;
    std::cout << "Vvedit klas tochnosti (%): ";
    std::cin >> acc;

    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    vstanovytyNazvu(name);
    vstanovytyOpir(r);
    vstanovytyPotuzhnist(p);
    vstanovytyTochnist(acc);
}

void Rezystor::vstanovytyOpir(double r) {
    if (r > 0.0) opir = r;
    else {
        opir = 1.0;
        std::cout << "[uvaga] Nekorektnyi opir. Vstanovleno 1.0 Om\n";
    }
}

void Rezystor::vstanovytyPotuzhnist(double p) {
    if (p > 0.0) potuzhnist = p;
    else {
        potuzhnist = 0.25;
        std::cout << "[uvaga] Nekorektna potuzhnist. Vstanovleno 0.25 W\n";
    }
}

void Rezystor::vstanovytyTochnist(double acc) {
    if (acc > 0.0 && acc <= 20.0) tochnist = acc;
    else {
        tochnist = 5.0;
        std::cout << "[uvaga] Nekorektna tochnist. Vstanovleno 5%\n";
    }
}

void Rezystor::vstanovytyNazvu(const std::string& name) {
    if (!name.empty()) nazva = name;
    else {
        nazva = "beznazvyi";
        std::cout << "[uvaga] Porozhnya nazva. Vstanovleno 'beznazvyi'\n";
    }
}

void zminytyTochnist(Rezystor& r, double nova) {
    r.vstanovytyTochnist(nova);
}

void mashstabuvatyOpir(Rezystor& r, double k) {
    if (k <= 0.0) {
        std::cout << "[uvaga] Nekorektnyi koefitsiyent. Propushcheno\n";
        return;
    }
    r.vstanovytyOpir(r.otrymatyOpir() * k);
}

void drukuvatyConstRef(const Rezystor& r) {
    r.vyvesty();
}

void pominyatyMistsiamy(Rezystor& a, Rezystor& b) {
    Rezystor temp = a;
    a = b;
    b = temp;
}

void kopiyuvatyZdo(Rezystor& dzherelo, Rezystor& prymach) {
    prymach.vstanovytyNazvu(dzherelo.otrymatyNazvu());
    prymach.vstanovytyOpir(dzherelo.otrymatyOpir());
    prymach.vstanovytyPotuzhnist(dzherelo.otrymatyPotuzhnist());
    prymach.vstanovytyTochnist(dzherelo.otrymatyTochnist());
}
