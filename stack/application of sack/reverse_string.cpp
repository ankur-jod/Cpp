#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        data[++top] = value;
    }

    char pop() {
        if (top == -1) {
            std::cout << "Stack Underflow!" << std::endl;
            return '\0';
        }
        return data[top--];
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    std::string str = "Hello, World!";
    std::cout << "Original String: " << str << std::endl;

    Stack charStack;
    for (int i = str.length() - 1; i >= 0; i--) {
        charStack.push(str[i]);
    }

    std::cout << "Reversed String: ";
    while (!charStack.empty()) {
        std::cout << charStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
