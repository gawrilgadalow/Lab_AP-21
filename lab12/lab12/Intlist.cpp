#include "IntList.h"
#include <algorithm> // remove_if, find

IntList::IntList(const std::vector<int>& v) : data(v) {}

// Vvedennia spysku z klaviatury
void IntList::input() {
    std::size_t n;
    std::cout << "Vvedit kilkist elementiv spysku: ";
    std::cin >> n;

    data.clear();
    data.reserve(n);

    std::cout << "Vvedit " << n << " tsilykh chysel: ";
    for (std::size_t i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        data.push_back(x);
    }
}

// Vyvid spysku
void IntList::print() const {
    std::cout << *this;
}

std::size_t IntList::size() const {
    return data.size();
}

// Porivniannia za kilkistiu elementiv
bool IntList::operator>=(const IntList& other) const {
    return this->data.size() >= other.data.size();
}

bool IntList::operator>(const IntList& other) const {
    return this->data.size() > other.data.size();
}

// Viluchennia u-sia yavnoho znachennia value zi spysku
IntList IntList::operator-(int value) const {
    IntList result(*this);
    auto& v = result.data;

    v.erase(
        std::remove(v.begin(), v.end(), value),
        v.end()
    );

    return result;
}

// Viluchennia elementiv inshogo spysku (po znachenniu)
IntList IntList::operator-(const IntList& other) const {
    IntList result(*this);
    auto& v = result.data;
    const auto& del = other.data;

    v.erase(
        std::remove_if(v.begin(), v.end(),
            [&del](int x) {
                return std::find(del.begin(), del.end(), x) != del.end();
            }),
        v.end()
    );

    return result;
}

// Operator vyvodu
std::ostream& operator<<(std::ostream& os, const IntList& lst) {
    os << "[size=" << lst.data.size() << "] { ";
    for (int x : lst.data) {
        os << x << ' ';
    }
    os << "}";
    return os;
}
