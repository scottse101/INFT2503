#include "set.hpp"
#include <iostream>

int main() {
    Set set1;
    Set set2;

    set1.add(1);
    set1.add(4);
    set1.add(3);

    set2.add(4);
    set2.add(7);

    std::cout << "Set 1: ";
    set1.print();

    std::cout << "Set 2: ";
    set2.print();

    Set unionSet = set1.unionWith(set2);
    std::cout << "Unionen av Set 1 og Set 2: ";
    unionSet.print();

    set1.setEqual(set2);
    std::cout << "Set 1 etter å ha satt lik Set 2: ";
    set1.print();

    return 0;
}
