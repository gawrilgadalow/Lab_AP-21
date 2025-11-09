#ifndef POWERSOURCE_H
#define POWERSOURCE_H

#include <iostream>
#include <string>

class PowerSource {
protected:
    std::string name;
    double power;      // in W
    double capacity;   // in Wh

public:
    PowerSource(const std::string& n = "Unknown", double p = 0, double c = 0);
    virtual ~PowerSource();

    virtual void input();
    virtual void display() const;

    double getPower() const { return power; }
    double getCapacity() const { return capacity; }
    std::string getName() const { return name; }
};

#endif
