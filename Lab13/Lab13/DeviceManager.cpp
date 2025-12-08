#include "DeviceManager.h"
#include <fstream>
#include <stdexcept>
#include <typeinfo>

using std::string;
using std::unique_ptr;
using std::make_unique;

void DeviceManager::add(unique_ptr<PowerSource> dev) {
    Record r;
    r.device = std::move(dev);
    records.push_back(std::move(r));
}

void DeviceManager::printAll() const {
    if (records.empty()) {
        std::cout << "Spysok prystroiv pustyi.\n";
        return;
    }
    std::cout << "=== Spysok prystroiv ===\n";
    for (const auto& r : records) {
        std::cout << *r.device << "-----------------\n";
    }
}

double DeviceManager::totalPower() const {
    double sum = 0.0;
    for (const auto& r : records) {
        sum += r.device->getPower();
    }
    return sum;
}

void DeviceManager::saveToFile(const string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Ne mozhu vidkryty fail dlia zapysu");
    }

    // spochatku kilkist
    out << records.size() << "\n";
    // kozhen zapys
    for (const auto& r : records) {
        r.device->saveToFile(out);
    }
}

void DeviceManager::loadFromFile(const string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Ne mozhu vidkryty fail dlia chytannia");
    }

    records.clear();
    std::size_t n;
    in >> n;
    if (!in) {
        throw std::runtime_error("Pomylka chytannia kilkosti z failu");
    }

    for (std::size_t i = 0; i < n; ++i) {
        char type;
        in >> type;
        if (!in) {
            throw std::runtime_error("Pomylka chytannia typa obiekta");
        }

        unique_ptr<PowerSource> dev;

        if (type == 'P') {
            dev = make_unique<Powerbank>();
        }
        else if (type == 'G') {
            dev = make_unique<Generator>();
        }
        else {
            throw std::runtime_error("Nevdomyi typ obiekta u faili");
        }

        dev->loadFromFile(in);
        add(std::move(dev));
    }
}

DeviceManager DeviceManager::operator+(const DeviceManager& other) const {
    DeviceManager res;

    // hlyboke kopiiuvannia cherez typ-kod + loadFromFile/saveToFile ne robyt opirno,
    // proste perenesenia potuzhnosti dlia prikladu moglo b buty,
    // ale zroby mozhlyve dlia zalyku: kopiiuemo tekstom
    for (const auto& r : records) {
        // vykorystai typid/ dynamic_cast
        if (dynamic_cast<Powerbank*>(r.device.get())) {
            auto* pb = dynamic_cast<Powerbank*>(r.device.get());
            auto copy = std::make_unique<Powerbank>(*pb);
            res.add(std::move(copy));
        }
        else if (dynamic_cast<Generator*>(r.device.get())) {
            auto* g = dynamic_cast<Generator*>(r.device.get());
            auto copy = std::make_unique<Generator>(*g);
            res.add(std::move(copy));
        }
    }

    for (const auto& r : other.records) {
        if (dynamic_cast<Powerbank*>(r.device.get())) {
            auto* pb = dynamic_cast<Powerbank*>(r.device.get());
            auto copy = std::make_unique<Powerbank>(*pb);
            res.add(std::move(copy));
        }
        else if (dynamic_cast<Generator*>(r.device.get())) {
            auto* g = dynamic_cast<Generator*>(r.device.get());
            auto copy = std::make_unique<Generator>(*g);
            res.add(std::move(copy));
        }
    }

    return res;
}
