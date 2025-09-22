#include "Resistor.h"
#include <iostream>
#include <limits>
#include <clocale>

void showMenu();
void clearInputBuffer();

int main() {
    std::setlocale(LC_ALL, "uk_UA.UTF-8");
    Resistor resistor_manager;
    int choice;

    do {
        showMenu();
        std::cout << "Ââåäiòü âàø âèáið: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
        case 1: {
            double resistance, power;
            int accuracy;
            std::cout << "Ââåäiòü íîìiíàëüíèé îïið: ";
            std::cin >> resistance;
            std::cout << "Ââåäiòü ìàêñèìàëüíó ïîòóæíiñòü: ";
            std::cin >> power;
            std::cout << "Ââåäiòü êëàñ òî÷íîñòi: ";
            std::cin >> accuracy;
            resistor_manager.addRes³stor(resistance, power, accuracy);
            break;
        }
        case 2: {
            int index;
            double resistance, power;
            int accuracy;
            std::cout << "Ââåäiòü iíäåêñ äëÿ âñòàâêè: ";
            std::cin >> index;
            std::cout << "Ââåäiòü íîìiíàëüíèé îïið: ";
            std::cin >> resistance;
            std::cout << "Ââåäiòü ìàêñèìàëüíó ïîòóæíiñòü: ";
            std::cin >> power;
            std::cout << "Ââåäiòü êëàñ òî÷íîñòi: ";
            std::cin >> accuracy;
            resistor_manager.³nsertRes³stor(index, resistance, power, accuracy);
            break;
        }
        case 3: {
            int index;
            std::cout << "Ââåäiòü iíäåêñ äëÿ âèäàëåííÿ: ";
            std::cin >> index;
            resistor_manager.eraseRes³stor(index);
            break;
        }
        case 4: {
            int index1, index2;
            std::cout << "Ââåäiòü ïåðøèé iíäåêñ äëÿ îáìiíó: ";
            std::cin >> index1;
            std::cout << "Ââåäiòü äðóãèé iíäåêñ äëÿ îáìiíó: ";
            std::cin >> index2;
            resistor_manager.swapRes³stors(index1, index2);
            break;
        }
        case 5:
            resistor_manager.clearAll();
            break;
        case 6:
            resistor_manager.pr³ntAllRes³stors();
            break;
        case 7: {
            int index;
            std::cout << "Ââåäiòü iíäåêñ äëÿ ðåäàãóâàííÿ: ";
            std::cin >> index;
            resistor_manager.ed³tRes³stor(index);
            break;
        }
        case 8:
            std::cout << "Ïîòî÷íà êiëüêiñòü ðåçiñòîðiâ: " << resistor_manager.getS³ze() << std::endl;
            break;
        case 0:
            std::cout << "Ïðîãðàìà çàâåðøóºòüñÿ." << std::endl;
            break;
        default:
            std::cout << "Íåêîðåêòíèé âèáið. Ñïðîáóéòå ùå ðàç." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

void showMenu() {
    std::cout << "\n--- ÌÅÍÞ ---" << std::endl;
    std::cout << "1. Äîäàòè ðåçiñòîð" << std::endl;
    std::cout << "2. Âñòàâèòè ðåçiñòîð çà iíäåêñîì" << std::endl;
    std::cout << "3. Âèäàëèòè ðåçiñòîð çà iíäåêñîì" << std::endl;
    std::cout << "4. Îáìiíÿòè äâà ðåçiñòîðè" << std::endl;
    std::cout << "5. Î÷èñòèòè âåñü ìàñèâ" << std::endl;
    std::cout << "6. Âèâåñòè âñi ðåçiñòîðè" << std::endl;
    std::cout << "7. Ðåäàãóâàòè ðåçiñòîð" << std::endl;
    std::cout << "8. Âèâåñòè êiëüêiñòü ðåçiñòîðiâ" << std::endl;
    std::cout << "0. Âèéòè" << std::endl;
}

// Funkts³ia dlia och³shchennia bufera vvedennia
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}