#pragma once
#include <vector>
#include <iostream>

class Set {
private:
    std::vector<int> elements;

public:
    void add(int element);

    Set unionWith(const Set& other) const;

    void setEqual(const Set& other);

    void print() const;
};
