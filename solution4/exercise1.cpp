#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> tall = {1.2, 2.6, 3.1, 4.7, 5.6};
    
    std::cout << "Første element (front): " << tall.front() << std::endl;
    std::cout << "Siste element (back): " << tall.back() << std::endl;

    tall.emplace(tall.begin(), 0.0);
    std::cout << "Første element etter emplace: " << tall.front() << std::endl;

    double søkeverdi = 4.7;
    auto it = std::find(tall.begin(), tall.end(), søkeverdi);
    
    if (it != tall.end()) {
        std::cout << "Element funnet: " << *it << std::endl;
    } else {
        std::cout << "Element ikke funnet." << std::endl;
    }

    return 0;
}
