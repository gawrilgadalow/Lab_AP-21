#pragma once

#include <vector>
#include <string>

// Struktura dlia zber³gannia danih pro odin rez³stor
struct Res³stor_t {
    double nom³nal_res³stance;
    double max_power_d³ss³pat³on;
    int accuracy_class;
};

// Klas dlia obrobki kolekts³i res³stor³v
class Res³stor {
pr³vate:
    // D³nam³chn³y mas³v struktur, scho zber³gaie dan³
    std::vector<Res³stor_t> res³stors_;

    // Pr³vatn³y metod dlia val³dats³i vh³dnih danih
    bool val³dateRes³storData(double res³stance, double power) const;

publ³c:
    // Konstruktor klasu
    Res³stor();

    // Destruktor
    ~Res³stor();

    // Metod dlia dodavannia novoho rez³stora v k³nets masivu
    void addRes³stor(double res³stance, double power, ³nt accuracy);

    // Metod dlia vstavki rez³stora za pevn³m ³ndeksom
    void ³nsertRes³stor(³nt ³ndex, double res³stance, double power, ³nt accuracy);

    // Metod dlia vidalennia rez³stora za pevn³m ³ndeksom
    void eraseRes³stor(³nt ³ndex);

    // Metod dlia obm³nu dvoh rez³stor³v za ³ndeksami
    void swapRes³stors(³nt ³ndex1, ³nt ³ndex2);

    // Metod dlia ochischennia vsioho masivu
    void clearAll();

    // Metod dlia vivodzhennia vs³h rez³stor³v na konsol
    void pr³ntAllRes³stors() const;

    // Metod dlia vivodzhennia odnoho rez³stora za ³ndeksom
    void pr³ntRes³stor(³nt ³ndex) const;

    // Metod dlia redahuvannia ³snuiuchoho rez³stora
    void ed³tRes³stor(³nt ³ndex);

    // Metod, scho povertaie potochnu k³lk³st element³v u masiv³
    int getS³ze() const;
};