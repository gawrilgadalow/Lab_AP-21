#ifndef POWERBANK_H
#define POWERBANK_H

#include "PowerSource.h"

class Powerbank : public PowerSource {
    int usbPorts;
    bool fastCharge;

public:
    Powerbank(const std::string& n = "Powerbank", double p = 20, double c = 10000,
        int ports = 2, bool fast = true);
    ~Powerbank() override;

    void input() override;
    void display() const override;
};

#endif
