#ifndef GENERATOR_H
#define GENERATOR_H

#include "PowerSource.h"

class Generator : public PowerSource {
    std::string fuelType;
    double fuelConsumption;

public:
    Generator(const std::string& n = "Generator", double p = 2000, double c = 5000,
        const std::string& fuel = "Benzyn", double cons = 1.2);
    ~Generator() override;

    void input() override;
    void display() const override;
};

#endif
