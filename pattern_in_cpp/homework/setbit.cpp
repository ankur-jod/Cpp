#include <iostream>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int num1 = 10, num2 = 15;
    std::cout << "Number of set bits in " << num1 << ": " << countSetBits(num1) << std::endl;
    std::cout << "Number of set bits in " << num2 << ": " << countSetBits(num2) << std::endl;
    return 0;
}
