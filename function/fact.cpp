#include <iostream>

int factorial(long n) {
    long result = 1;
    if(n<0)
        return -1;  // Wrong input
    for (long i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}
