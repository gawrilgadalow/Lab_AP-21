#pragma once
#ifndef POWERSOURCE_H
#define POWERSOURCE_H

#include <string>
#include <iostream>
using namespace std;

class PowerFriend;  // forward declaration

class PowerSource {
private:
    string name;
    double power;      // W
    double capacity;   // Wh

public:
    PowerSource(const string& n = "Unknown", double p = 0, double c = 0);
    virtual ~PowerSource();

    virtual void input();
    virtual void display() const;

    friend class PowerFriend;   // 🔥 дружній клас отримує доступ до приватних полів
};

#endif
