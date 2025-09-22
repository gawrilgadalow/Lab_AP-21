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
        std::cout << "����i�� ��� ���i�: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
        case 1: {
            double resistance, power;
            int accuracy;
            std::cout << "����i�� ���i������� ��i�: ";
            std::cin >> resistance;
            std::cout << "����i�� ����������� ������i���: ";
            std::cin >> power;
            std::cout << "����i�� ���� �������i: ";
            std::cin >> accuracy;
            resistor_manager.addRes�stor(resistance, power, accuracy);
            break;
        }
        case 2: {
            int index;
            double resistance, power;
            int accuracy;
            std::cout << "����i�� i����� ��� �������: ";
            std::cin >> index;
            std::cout << "����i�� ���i������� ��i�: ";
            std::cin >> resistance;
            std::cout << "����i�� ����������� ������i���: ";
            std::cin >> power;
            std::cout << "����i�� ���� �������i: ";
            std::cin >> accuracy;
            resistor_manager.�nsertRes�stor(index, resistance, power, accuracy);
            break;
        }
        case 3: {
            int index;
            std::cout << "����i�� i����� ��� ���������: ";
            std::cin >> index;
            resistor_manager.eraseRes�stor(index);
            break;
        }
        case 4: {
            int index1, index2;
            std::cout << "����i�� ������ i����� ��� ���i��: ";
            std::cin >> index1;
            std::cout << "����i�� ������ i����� ��� ���i��: ";
            std::cin >> index2;
            resistor_manager.swapRes�stors(index1, index2);
            break;
        }
        case 5:
            resistor_manager.clearAll();
            break;
        case 6:
            resistor_manager.pr�ntAllRes�stors();
            break;
        case 7: {
            int index;
            std::cout << "����i�� i����� ��� �����������: ";
            std::cin >> index;
            resistor_manager.ed�tRes�stor(index);
            break;
        }
        case 8:
            std::cout << "������� �i���i��� ���i����i�: " << resistor_manager.getS�ze() << std::endl;
            break;
        case 0:
            std::cout << "�������� �����������." << std::endl;
            break;
        default:
            std::cout << "����������� ���i�. ��������� �� ���." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

void showMenu() {
    std::cout << "\n--- ���� ---" << std::endl;
    std::cout << "1. ������ ���i����" << std::endl;
    std::cout << "2. �������� ���i���� �� i�������" << std::endl;
    std::cout << "3. �������� ���i���� �� i�������" << std::endl;
    std::cout << "4. ���i���� ��� ���i�����" << std::endl;
    std::cout << "5. �������� ���� �����" << std::endl;
    std::cout << "6. ������� ��i ���i�����" << std::endl;
    std::cout << "7. ���������� ���i����" << std::endl;
    std::cout << "8. ������� �i���i��� ���i����i�" << std::endl;
    std::cout << "0. �����" << std::endl;
}

// Funkts�ia dlia och�shchennia bufera vvedennia
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}