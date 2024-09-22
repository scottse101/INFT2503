#include <iostream>
#include <fstream>

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperatures[length];
    int countBelow10 = 0;
    int count10to20 = 0;
    int countAbove20 = 0;

    read_temperatures(temperatures, length);

    for (int i = 0; i < length; i++) {
        if (temperatures[i] < 10) {
            countBelow10++;
        } else if (temperatures[i] <= 20) {
            count10to20++;
        } else {
            countAbove20++;
        }
    }

    std::cout << "Antall under 10 er " << countBelow10 << std::endl;
    std::cout << "Antall mellom 10 og 20 er " << count10to20 << std::endl;
    std::cout << "Antall over 20 er " << countAbove20 << std::endl;

    return 0;
}

void read_temperatures(double temperatures[], int length) {
    std::ifstream infile("readTemp.txt");

    if (!infile) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    for (int i = 0; i < length; i++) {
        infile >> temperatures[i];
    }

    infile.close();
}
