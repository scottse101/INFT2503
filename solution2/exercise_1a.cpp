#include <iostream>

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << "Address of i: " << &i << ", Value of i: " << i << std::endl;
    std::cout << "Address of j: " << &j << ", Value of j: " << j << std::endl;
    std::cout << "Address stored in p: " << p << ", Value pointed to by p: " << *p << std::endl;
    std::cout << "Address stored in q: " << q << ", Value pointed to by q: " << *q << std::endl;

    return 0;
}

