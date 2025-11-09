#include <iostream>
#include <vector>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"

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

    return 0;
}
