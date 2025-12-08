#ifndef GENERATOR_H
#define GENERATOR_H

#include "PowerSource.h"

// Dochirnii klas – benzynovyi/dyzel-heenerator
class Generator : public PowerSource {
private:
    std::string fuelType;
    double fuelConsumption; // l/h

public:
    Generator(const std::string& n = "Generator",
        double p = 2000.0,
        const std::string& fuel = "Benzyn",
        double cons = 1.2);

    void load(std::istream& in) override;
    void print(std::ostream& out) const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    char typeCode() const override { return 'G'; }
};

#endif
#pragma once
