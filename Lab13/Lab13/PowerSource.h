#ifndef POWERSOURCE_H
#define POWERSOURCE_H

#include <iostream>
#include <string>
#include <memory>

class PowerSource {
protected:
    std::string name;
    double power;

public:
    PowerSource(const std::string& n = "Unknown", double p = 0.0);
    virtual ~PowerSource() = default;

    virtual void load(std::istream& in);
    virtual void print(std::ostream& out) const;

    virtual void saveToFile(std::ostream& out) const = 0;
    virtual void loadFromFile(std::istream& in) = 0;
    virtual char typeCode() const = 0;

    virtual std::unique_ptr<PowerSource> clone() const = 0;

    double getPower() const { return power; }

    friend std::ostream& operator<<(std::ostream& out, const PowerSource& src) {
        src.print(out);
        return out;
    }
};

#endif
