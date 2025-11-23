#ifndef INTLIST_H
#define INTLIST_H

#include <vector>
#include <iostream>

class IntList {
private:
    std::vector<int> data;

public:
    // Конструктори
    IntList() = default;
    explicit IntList(const std::vector<int>& v);

    // Методи
    void input();              // vvedennia spysku
    void print() const;        // vyvid spysku
    std::size_t size() const;  // kilkist elementiv

    // Оператор >= : porivniannia za kilkistiu elementiv
    bool operator>=(const IntList& other) const;

    // Оператор > : zручно мати ще й strict greater
    bool operator>(const IntList& other) const;

    // Оператор - (int): viluchennia zadanoho elementa zi spysku (po znachenniu)
    IntList operator-(int value) const;

    // Оператор - (IntList): viluchennia elementiv, yaki mistiatsia v inshomu spysku
    IntList operator-(const IntList& other) const;

    // Доступ до вектора (тільки для читання – раптом треба)
    const std::vector<int>& getData() const { return data; }

    // Дружній оператор виводу
    friend std::ostream& operator<<(std::ostream& os, const IntList& lst);
};

#endif
#pragma once
