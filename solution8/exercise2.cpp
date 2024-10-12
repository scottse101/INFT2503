#include <iostream>
#include <utility> 
#include <iomanip> 

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 a, T2 b) : first(a), second(b) {}

    auto operator+(const Pair& other) {
        return Pair(first + other.first, second + other.second);
    }

    bool operator>(const Pair& other) {
        return (first + second) > (other.first + other.second);
    }

    bool operator<(const Pair& other) {
        return (first + second) < (other.first + other.second);
    }

    void print() const {
        std::cout << "(" << first << ", " << second << ")";
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);

    std::cout << "p1: ";
    p1.print();
    std::cout << std::endl;

    std::cout << "p2: ";
    p2.print();
    std::cout << std::endl;

    if (p1 > p2)
        std::cout << "p1 er størst" << std::endl;
    else
        std::cout << "p2 er størst" << std::endl;

    auto sum = p1 + p2;
    std::cout << "Sum: ";
    sum.print();
    std::cout << std::endl;

    return 0;
}
