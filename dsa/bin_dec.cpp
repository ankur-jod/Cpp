#include <iostream>
#include <stack>

std::string decimalToBinary(int decimal) {
    std::stack<int> binaryStack;

    while (decimal > 0) {
        binaryStack.push(decimal % 2);
        decimal /= 2;
    }

    std::string binary = "";
    while (!binaryStack.empty()) {
        binary += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binary;
}

int main() {
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::string binary = decimalToBinary(decimal);
    std::cout << "Binary representation: " << binary << std::endl;

    return 0;
}
