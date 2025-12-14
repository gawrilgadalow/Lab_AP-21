#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"

class DeviceManager {
private:
    std::vector<std::unique_ptr<PowerSource>> devices;

public:
    DeviceManager() = default;

    DeviceManager(const DeviceManager& other);
    DeviceManager& operator=(const DeviceManager& other);

    DeviceManager(DeviceManager&&) noexcept = default;
    DeviceManager& operator=(DeviceManager&&) noexcept = default;

    void add(std::unique_ptr<PowerSource> dev);

    void printAll() const;
    double totalPower() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    DeviceManager operator+(const DeviceManager& other) const;
};

#endif
