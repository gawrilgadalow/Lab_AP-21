#ifndef REZYSTOR_H
#define REZYSTOR_H

#include <iostream>
#include <string>
#include <stdexcept>

class Rezystor {
private:
    double opir;
    double potuzhnist;
    double tochnist;
    std::string nazva;

public:
    Rezystor();
    Rezystor(double r, double p, double acc, const std::string& name);
    ~Rezystor();

    void vyvesty() const;
    void vvodyty();

    void vstanovytyOpir(double r);
    void vstanovytyPotuzhnist(double p);
    void vstanovytyTochnist(double acc);
    void vstanovytyNazvu(const std::string& name);

    double otrymatyOpir() const { return opir; }
    double otrymatyPotuzhnist() const { return potuzhnist; }
    double otrymatyTochnist() const { return tochnist; }
    const std::string& otrymatyNazvu() const { return nazva; }
};

void zminytyTochnist(Rezystor& r, double nova);
void mashstabuvatyOpir(Rezystor& r, double k);
void drukuvatyConstRef(const Rezystor& r);
void pominyatyMistsiamy(Rezystor& a, Rezystor& b);
void kopiyuvatyZdo(Rezystor& dzherelo, Rezystor& prymach);

#endif
