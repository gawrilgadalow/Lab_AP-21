#include <iostream>
#include <vector>
#include "PowerSource.h"
#include "Powerbank.h"
#include "Generator.h"
#include "PowerFriend.h"

using namespace std;

int main() {
    vector<PowerSource*> devices;

    Powerbank pb;
    Generator gen;

    cout << "=== Vvedennia Powerbank ===\n";
    pb.input();

    cout << "\n=== Vvedennia Generatora ===\n";
    gen.input();

    devices.push_back(&pb);
    devices.push_back(&gen);

    PowerFriend helper;

    cout << "\n=== Vyvedennia danikh (friend class) ===\n";
    helper.showAll(devices);

    cout << "\n=== Suma potuzhnosti ===\n";
    cout << "Total power = " << helper.totalPower(devices) << " W\n";

    return 0;
}
