#include "DeviceManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

DeviceManager::DeviceManager(const DeviceManager& other) {
    for (const auto& d : other.devices) {
        devices.push_back(d->clone());
    }
}

DeviceManager& DeviceManager::operator=(const DeviceManager& other) {
    if (this == &other) return *this;
    devices.clear();
    for (const auto& d : other.devices) {
        devices.push_back(d->clone());
    }
    return *this;
}

void DeviceManager::add(std::unique_ptr<PowerSource> dev) {
    devices.push_back(std::move(dev));
}

void DeviceManager::printAll() const {
    if (devices.empty()) {
        std::cout << "List is empty\n";
        return;
    }
    for (const auto& d : devices) {
        std::cout << *d << "----------------\n";
    }
}

double DeviceManager::totalPower() const {
    double sum = 0.0;
    for (const auto& d : devices) {
        sum += d->getPower();
    }
    return sum;
}

void DeviceManager::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot open file for writing");

    out << devices.size() << "\n";
    for (const auto& d : devices) {
        d->saveToFile(out);
    }
}

void DeviceManager::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Cannot open file for reading");

    devices.clear();
    size_t n;
    in >> n;

    for (size_t i = 0; i < n; ++i) {
        char type;
        in >> type;

        std::unique_ptr<PowerSource> dev;
        if (type == 'P') dev = std::make_unique<Powerbank>();
        else if (type == 'G') dev = std::make_unique<Generator>();
        else throw std::runtime_error("Unknown device type");

        dev->loadFromFile(in);
        devices.push_back(std::move(dev));
    }
}

DeviceManager DeviceManager::operator+(const DeviceManager& other) const {
    DeviceManager result;
    for (const auto& d : devices)
        result.devices.push_back(d->clone());
    for (const auto& d : other.devices)
        result.devices.push_back(d->clone());
    return result;
}
