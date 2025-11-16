#ifndef POWERFRIEND_H
#define POWERFRIEND_H

#include <vector>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"

class PowerFriend {
public:
    void showAll(const vector<PowerSource*>& vec) const;

    // 🔥 Пункт 7 — математична операція зі спільним параметром
    double totalPower(const vector<PowerSource*>& vec) const;
};

#endif
