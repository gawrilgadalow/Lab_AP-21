#ifndef GENERATOR_H
#define GENERATOR_H

#include "PowerSource.h"

class Generator : public PowerSource {
private:
    std::string fuelType;
    double fuelConsumption;

public:
    Generator(const std::string& n = "Generator",
        double p = 2000.0,
        const std::string& fuel = "Gasoline",
        double cons = 1.2);

    void load(std::istream& in) override;
    void print(std::ostream& out) const override;

    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;

    char typeCode() const override { return 'G'; }

    std::unique_ptr<PowerSource> clone() const override {
        return std::make_unique<Generator>(*this);
    }
};

#endif
