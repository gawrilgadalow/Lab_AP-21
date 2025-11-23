#include <iostream>
#include <vector>
#include <algorithm>
#include "IntList.h"

int main() {
    std::size_t m;
    std::cout << "Vvedit kilkist spyskiv: ";
    std::cin >> m;

    std::vector<IntList> lists(m);

    // Vvedennia spyskiv
    for (std::size_t i = 0; i < m; ++i) {
        std::cout << "\nSpysok #" << i << ":\n";
        lists[i].input();
    }

    std::cout << "\n=== Pochatkovi spysky ===\n";
    for (std::size_t i = 0; i < lists.size(); ++i) {
        std::cout << "Spysok #" << i << ": " << lists[i] << "\n";
    }

    // Demonstratsiia operatora -(int): viluchennia zadanoho chysla z pershoho spysku
    if (!lists.empty()) {
        int value;
        std::cout << "\nVvedit znachennia, yke treba vydalyty z pershoho spysku: ";
        std::cin >> value;

        IntList modified = lists[0] - value;
        std::cout << "Pershyi spysok pislia viluchennia " << value << ": "
            << modified << "\n";
    }

    // Posk k spets spysku z NAIMENShoiu kilkistiu elementiv
    if (lists.empty()) {
        std::cout << "Nema spyskiv.\n";
        return 0;
    }

    std::size_t minIndex = 0;
    for (std::size_t i = 1; i < lists.size(); ++i) {
        if (lists[i].size() < lists[minIndex].size()) {
            minIndex = i;
        }
    }

    IntList minList = lists[minIndex];
    std::cout << "\nSpysok z naimenshoyu kilkistiu elementiv (index = "
        << minIndex << "): " << minList << "\n";

    // Sortuvannia masyvu spyskiv za spadanniam kilkosti elementiv
    std::sort(lists.begin(), lists.end(),
        [](const IntList& a, const IntList& b) {
            return a.size() > b.size(); // spadannia
        });

    std::cout << "\n=== Spysky pislia sortuvannia za spadanniam kilkosti elementiv ===\n";
    for (std::size_t i = 0; i < lists.size(); ++i) {
        std::cout << "Spysok #" << i << ": " << lists[i] << "\n";
    }

    // Viluchyty z kozhnoho spysku elementy spysku z naimenshoyu kilkistiu
    std::cout << "\n=== Viluchennia elementiv spysku-minimuma z kozhnoho spysku ===\n";
    for (std::size_t i = 0; i < lists.size(); ++i) {
        lists[i] = lists[i] - minList;
    }

    std::cout << "\n=== Rezultat pislia viluchennia ===\n";
    for (std::size_t i = 0; i < lists.size(); ++i) {
        std::cout << "Spysok #" << i << ": " << lists[i] << "\n";
    }

    return 0;
}
