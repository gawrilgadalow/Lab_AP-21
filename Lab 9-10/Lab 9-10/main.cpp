#include <iostream>
#include <vector>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"

void analyzePower(const std::vector<PowerSource*>& sources) {
    if (sources.empty()) {
        std::cout << "Nema obiektiv dlia analizu.\n";
        return;
    }

    double sum = 0;
    double maxPower = sources[0]->getPower();
    double minPower = sources[0]->getPower();

    for (const auto* s : sources) {
        double p = s->getPower();
        sum += p;
        if (p > maxPower) maxPower = p;
        if (p < minPower) minPower = p;
    }

    double avg = sum / sources.size();

    std::cout << "\n=== Analiz potuzhnosti ===\n";
    std::cout << "Sumarna potuzhnist: " << sum << " W\n";
    std::cout << "Srednia potuzhnist: " << avg << " W\n";
    std::cout << "Maksymalna potuzhnist: " << maxPower << " W\n";
    std::cout << "Minimalna potuzhnist: " << minPower << " W\n";
}

int main() {
    std::vector<PowerSource*> sources;

    Powerbank pb;
    Generator gen;

    std::cout << "=== Vvedennia Powerbank ===\n";
    pb.input();

    std::cout << "\n=== Vvedennia Generatora ===\n";
    gen.input();

    sources.push_back(&pb);
    sources.push_back(&gen);

    std::cout << "\n=== Vyvedennia danikh ===\n";
    for (const auto* src : sources) {
        src->display();
        std::cout << "------------------------\n";
    }

    // 🔥 НОВИЙ ПУНКТ 7 — математичний аналіз параметрів
    analyzePower(sources);

    return 0;
}
