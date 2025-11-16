#ifndef GENERATOR_H
#define GENERATOR_H

#include "PowerSource.h"

class Generator : public PowerSource {
private:
    string fuelType;
    double fuelConsumption;

public:
    Generator(const string& n = "Generator", double p = 2000, double c = 5000,
        const string& fuel = "Benzyn", double cons = 1.2);
    ~Generator() override;

    void input() override;
    void display() const override;

    friend class PowerFriend;   // 🔥 дружній клас має доступ
};

#endif
