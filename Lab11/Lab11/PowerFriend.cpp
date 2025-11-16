#include "PowerFriend.h"

void PowerFriend::showAll(const vector<PowerSource*>& vec) const {
    for (auto* ps : vec) {
        ps->display();
        cout << "----------------------\n";
    }
}

double PowerFriend::totalPower(const vector<PowerSource*>& vec) const {
    double sum = 0;

    for (auto* ps : vec) {
        // 🔥 Прямий доступ до private полів
        sum += ps->power;
    }

    return sum;
}
