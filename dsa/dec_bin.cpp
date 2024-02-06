#include <iostream>
#include <stack>
#include <cmath>

int binaryToDecimal(std::string binary) {
    std::stack<int> stack;
    int decimal = 0;

    for (char digit : binary) {
        stack.push(digit - '0');
    }

    int power = 0;
    while (!stack.empty()) {
        decimal += stack.top() * pow(2, power);
        stack.pop();
        power++;
    }

    return decimal;
}

int main() {
    std::string binaryNumber;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);
    std::cout << "Decimal equivalent: " << decimalNumber << std::endl;

    return 0;
}
