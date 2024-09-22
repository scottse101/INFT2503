#include <iostream>

int main() {
    double number = 0.0;

    double *ptr = &number;

    double &ref = number;

    number = 10.5;
    std::cout << "Etter direkte tilordning: number = " << number << std::endl;

    *ptr = 20.5;
    std::cout << "Etter tilordning via peker: number = " << number << std::endl;

    ref = 30.5;
    std::cout << "Etter tilordning via referanse: number = " << number << std::endl;

    return 0;
}
