#include <iostream>
#include <stack>
#include <algorithm>

bool isOperator(char x) {
   return (x == '+' || x == '-' || x == '*' || x == '/');
}

std::string preToPost(std::string pre_exp) {

    std::stack<std::string> s;

    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--) {

        if (isOperator(pre_exp[i])) {

            std::string op1 = s.top(); s.pop();
            std::string op2 = s.top(); s.pop();

            std::string temp = op1 + op2 + pre_exp[i];

            s.push(temp);
        }

        else {
            s.push(std::string(1, pre_exp[i]));
        }
    }

    return s.top();
}

int main() {
    std::string pre_exp;
    std::cout << "Enter a prefix expression: ";
    std::cin >> pre_exp;
    std::cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}