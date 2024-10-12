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

    bool operator<(const Pair& other) {
        return (first + second) < (other.first + other.second);
    }

    void print() const {
        std::cout << "Pair: (" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    
    p1.print();
    p2.print();

    auto p3 = p1 + p2;
    std::cout << "Sum of pairs: ";
    p3.print();

    std::cout << std::boolalpha;
    std::cout << "Is p1 < p2? " << (p1 < p2) << std::endl;

    return 0;
}
