#pragma once
#ifndef POWERBANK_H
#define POWERBANK_H

#include "PowerSource.h"

// Dochirnii klas – pavåðbank
class Powerbank : public PowerSource {
private:
    double capacityWh;  // yemnist Wh
    int usbPorts;
    bool fastCharge;

public:
    Powerbank(const std::string& n = "Powerbank",
        double p = 20.0,
        double c = 10000.0,
        int ports = 2,
        bool fast = true);

    void load(std::istream& in) override;
    void print(std::ostream& out) const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    char typeCode() const override { return 'P'; }
};

#endif
