#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string postfixToPrefix(const std::string& postfix) {
    std::stack<std::string> stack;

    for (char c : postfix) {
        if (isOperator(c)) {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();

            std::string prefix = c + operand1 + operand2;
            stack.push(prefix);
        } else {
            stack.push(std::string(1, c));
        }
    }

    return stack.top();
}

int main() {
    std::string postfixExpression;
    std::cout << "Enter a postfix expression: ";
    std::cin >> postfixExpression;

    std::string prefixExpression = postfixToPrefix(postfixExpression);
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
