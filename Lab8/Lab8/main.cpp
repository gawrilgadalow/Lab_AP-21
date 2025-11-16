#include "resistor.h"

int main() {
    Rezystor r1;
    Rezystor r2(1000.0, 0.5, 1.0, "R1000_0p5W_1proc");

    drukuvatyConstRef(r1);
    drukuvatyConstRef(r2);

    Rezystor& pos_r2 = r2;
    zminytyTochnist(pos_r2, 2.0);
    mashstabuvatyOpir(pos_r2, 1.1);
    drukuvatyConstRef(r2);

    Rezystor r3;
    r3.vvodyty();
    drukuvatyConstRef(r3);

    pominyatyMistsiamy(r2, r3);
    std::cout << "[pislya obminu] r2:\n"; drukuvatyConstRef(r2);
    std::cout << "[pislya obminu] r3:\n"; drukuvatyConstRef(r3);

    kopiyuvatyZdo(r2, r1);
    std::cout << "[pislya kopiyuvannya r2 -> r1] r1:\n"; drukuvatyConstRef(r1);

    r1.vstanovytyOpir(-10.0);
    r1.vstanovytyPotuzhnist(0.0);
    r1.vstanovytyTochnist(50.0);
    drukuvatyConstRef(r1);

    return 0;
}
