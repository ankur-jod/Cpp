#include <iostream>
#include <stack>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string reverseString(const std::string& str) {
    std::string reversedStr;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }
    return reversedStr;
}

std::string infixToPrefix(const std::string& infix) {
    std::string prefix;
    std::stack<char> stack;

    // Reverse the infix expression
    std::string reversedInfix = reverseString(infix);

    for (char c : reversedInfix) {
        if (isalpha(c) || isdigit(c)) {
            prefix += c;
        } else if (c == ')') {
            stack.push(c);
        } else if (c == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove the ')'
        } else if (isOperator(c)) {
            while (!stack.empty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    // Reverse the prefix expression to get the final result
    std::string finalPrefix;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        finalPrefix += prefix[i];
    }

    return finalPrefix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter the infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string prefixExpression = infixToPrefix(infixExpression);
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
