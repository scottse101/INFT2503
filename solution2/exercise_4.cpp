#include <iostream>

int main() {
    int a = 5;
    int b = 0;   // b må initialiseres som en variabel, se linje 8
    int *c;
    c = &b;      // c peker på b
    a = b + *c;  // riktig bruk av a og *c i uttrykket
    b = 2;       // tilordning av verdi til b

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "*c = " << *c << std::endl;

    return 0;
}
