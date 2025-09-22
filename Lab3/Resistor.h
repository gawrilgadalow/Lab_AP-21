#pragma once

#include <vector>
#include <string>

// Struktura dlia zber�gannia danih pro odin rez�stor
struct Res�stor_t {
    double nom�nal_res�stance;
    double max_power_d�ss�pat�on;
    int accuracy_class;
};

// Klas dlia obrobki kolekts�i res�stor�v
class Res�stor {
pr�vate:
    // D�nam�chn�y mas�v struktur, scho zber�gaie dan�
    std::vector<Res�stor_t> res�stors_;

    // Pr�vatn�y metod dlia val�dats�i vh�dnih danih
    bool val�dateRes�storData(double res�stance, double power) const;

publ�c:
    // Konstruktor klasu
    Res�stor();

    // Destruktor
    ~Res�stor();

    // Metod dlia dodavannia novoho rez�stora v k�nets masivu
    void addRes�stor(double res�stance, double power, �nt accuracy);

    // Metod dlia vstavki rez�stora za pevn�m �ndeksom
    void �nsertRes�stor(�nt �ndex, double res�stance, double power, �nt accuracy);

    // Metod dlia vidalennia rez�stora za pevn�m �ndeksom
    void eraseRes�stor(�nt �ndex);

    // Metod dlia obm�nu dvoh rez�stor�v za �ndeksami
    void swapRes�stors(�nt �ndex1, �nt �ndex2);

    // Metod dlia ochischennia vsioho masivu
    void clearAll();

    // Metod dlia vivodzhennia vs�h rez�stor�v na konsol
    void pr�ntAllRes�stors() const;

    // Metod dlia vivodzhennia odnoho rez�stora za �ndeksom
    void pr�ntRes�stor(�nt �ndex) const;

    // Metod dlia redahuvannia �snuiuchoho rez�stora
    void ed�tRes�stor(�nt �ndex);

    // Metod, scho povertaie potochnu k�lk�st element�v u masiv�
    int getS�ze() const;
};