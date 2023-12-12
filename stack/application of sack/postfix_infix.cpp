#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string postfixToInfix(const std::string& postfix) {
    std::stack<std::string> stack;

    for (char c : postfix) {
        if (isOperator(c)) {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();

            std::string expression = "(" + operand1 + " " + c + " " + operand2 + ")";
            stack.push(expression);
        } else {
            stack.push(std::string(1, c));
        }
    }

    return stack.top();
}

int main() {
    std::string postfixExpression = "ab+c*";
    std::string infixExpression = postfixToInfix(postfixExpression);

    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
    std::cout << "Infix Expression: " << infixExpression << std::endl;

    return 0;
}
