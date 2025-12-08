#include <iostream>
#include <memory>
#include "DeviceManager.h"

using namespace std;

int main() {
    try {
        DeviceManager manager;

        cout << "Skilky prystroiv vvesty? ";
        size_t count;
        cin >> count;

        if (!cin || count == 0) {
            throw runtime_error("Nekorektna kilkist prystroiv");
        }

        for (size_t i = 0; i < count; ++i) {
            cout << "\nOberit typ prystroiu #" << i
                << " (1 - Powerbank, 2 - Generator): ";
            int t;
            cin >> t;

            if (!cin) throw runtime_error("Pomylka typa prystroiu");

            if (t == 1) {
                auto dev = make_unique<Powerbank>();
                cout << "Vvedit dlia Powerbank: name power capacityWh usbPorts fast(0/1):\n";
                dev->load(cin);
                manager.add(std::move(dev));
            }
            else if (t == 2) {
                auto dev = make_unique<Generator>();
                cout << "Vvedit dlia Generatora: name power fuelType fuelConsumption:\n";
                dev->load(cin);
                manager.add(std::move(dev));
            }
            else {
                throw runtime_error("Nevidomyi typ prystroiu");
            }
        }

        cout << "\nPochatkovyi spysok:\n";
        manager.printAll();
        cout << "Sumarna potuzhnist: " << manager.totalPower() << " W\n";

        // zapis u fail
        const string filename = "devices.txt";
        manager.saveToFile(filename);
        cout << "\nDani zberezheno u fail: " << filename << "\n";

        // stvorymo novyi manager i prochytaiemo z failu
        DeviceManager fromFile;
        fromFile.loadFromFile(filename);

        cout << "\nSpysok, prochytanyi z failu:\n";
        fromFile.printAll();
        cout << "Sumarna potuzhnist (z failu): " << fromFile.totalPower() << " W\n";

        // demonstratsiia perevantazhenoho operatora '+' (konkatenatsiia)
        DeviceManager merged = manager + fromFile;
        cout << "\nPislia konkatenatsii (manager + fromFile):\n";
        merged.printAll();
        cout << "Sumarna potuzhnist (merged): " << merged.totalPower() << " W\n";

    }
    catch (const std::exception& ex) {
        cerr << "Pomylka: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
