#include <iostream>
#include <memory>

using namespace std;

// =====  À¿— RESISTOR =====
class Resistor {
private:
    double resistance;   // Ohm
    double maxPower;     // W
    double accuracy;     // %

public:
    Resistor(double r, double p, double a)
        : resistance(r), maxPower(p), accuracy(a) {
        cout << "Resistor created\n";
    }

    ~Resistor() {
        cout << "Resistor destroyed\n";
    }

    void print() const {
        cout << "Resistance: " << resistance << " Ohm\n";
        cout << "Max power: " << maxPower << " W\n";
        cout << "Accuracy: " << accuracy << " %\n";
    }
};

// ===== ƒÀﬂ weak_ptr =====
class NodeB;

class NodeA {
public:
    shared_ptr<NodeB> b;
    ~NodeA() {
        cout << "NodeA destroyed\n";
    }
};

class NodeB {
public:
    weak_ptr<NodeA> a;
    ~NodeB() {
        cout << "NodeB destroyed\n";
    }
};

// ===== MAIN =====
int main() {

    cout << "=== unique_ptr ===\n";
    {
        unique_ptr<Resistor> r1 = make_unique<Resistor>(1000, 0.5, 5);
        r1->print();

        // unique_ptr cannot be copied
        // unique_ptr<Resistor> r2 = r1; // error

        unique_ptr<Resistor> r2 = move(r1);
        cout << "Ownership moved\n";

        if (!r1)
            cout << "r1 is nullptr\n";
    }
    cout << "End of unique_ptr block\n\n";

    cout << "=== shared_ptr ===\n";
    {
        shared_ptr<Resistor> s1 = make_shared<Resistor>(220, 0.25, 10);
        cout << "use_count: " << s1.use_count() << endl;

        shared_ptr<Resistor> s2 = s1;
        cout << "use_count after copy: " << s1.use_count() << endl;

        {
            shared_ptr<Resistor> s3 = s1;
            cout << "use_count inside block: " << s1.use_count() << endl;
        }

        cout << "use_count after block: " << s1.use_count() << endl;
    }
    cout << "End of shared_ptr block\n\n";

    cout << "=== weak_ptr ===\n";
    {
        auto a = make_shared<NodeA>();
        auto b = make_shared<NodeB>();

        a->b = b;
        b->a = a; // no cyclic dependency
    }
    cout << "End of weak_ptr block\n";

    return 0;
}
