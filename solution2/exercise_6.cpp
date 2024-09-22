#include <iostream>

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}

int main() {
    int table[20];
    for (int i = 0; i < 20; i++) {
        table[i] = i + 1;
    }

    int sum_first_10 = find_sum(table, 10);
    std::cout << "Sum of the first 10 elements: " << sum_first_10 << std::endl;

    int sum_next_5 = find_sum(&table[10], 5);
    std::cout << "Sum of the next 5 elements: " << sum_next_5 << std::endl;

    int sum_last_5 = find_sum(&table[15], 5);
    std::cout << "Sum of the last 5 elements: " << sum_last_5 << std::endl;

    return 0;
}