#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <vector>
#include <string>
#include <memory>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"

// klas-keruvalnyk, yakyi zberigaie danni u vektori struktur
class DeviceManager {
public:
    struct Record {
        std::unique_ptr<PowerSource> device;
    };

private:
    std::vector<Record> records;

public:
    DeviceManager() = default;
    ~DeviceManager() = default;

    void add(std::unique_ptr<PowerSource> dev);

    void printAll() const;
    double totalPower() const;

    // zapis u fail
    void saveToFile(const std::string& filename) const;
    // chytannia z failu
    void loadFromFile(const std::string& filename);

    // operator konkatenatsii dvokh manageriv
    DeviceManager operator+(const DeviceManager& other) const;
};

#endif
