#include <iostream>
#include <memory>
#include "DeviceManager.h"

using namespace std;

int main() {
    try {
        DeviceManager manager;

        size_t count;
        cout << "Enter number of devices: ";
        cin >> count;

        for (size_t i = 0; i < count; ++i) {
            int t;
            cout << "Device type (1-Powerbank, 2-Generator): ";
            cin >> t;

            if (t == 1) {
                auto d = make_unique<Powerbank>();
                d->load(cin);
                manager.add(move(d));
            }
            else if (t == 2) {
                auto d = make_unique<Generator>();
                d->load(cin);
                manager.add(move(d));
            }
            else {
                throw runtime_error("Invalid device type");
            }
        }

        cout << "\nInitial list:\n";
        manager.printAll();
        cout << "Total power: " << manager.totalPower() << " W\n";

        manager.saveToFile("devices.txt");

        DeviceManager fromFile;
        fromFile.loadFromFile("devices.txt");

        DeviceManager merged = manager + fromFile;
        cout << "\nMerged list:\n";
        merged.printAll();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
