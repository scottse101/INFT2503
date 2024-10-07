#include "set.hpp"
#include <algorithm>

void Set::add(int element) {
    if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
        elements.push_back(element);
    }
}

Set Set::unionWith(const Set& other) const {
    Set resultSet = *this; 

    for (int elem : other.elements) {
        resultSet.add(elem); 
    }

    return resultSet;
}

void Set::setEqual(const Set& other) {
    elements = other.elements; 
}

void Set::print() const {
    std::cout << "{ ";
    for (int elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}
