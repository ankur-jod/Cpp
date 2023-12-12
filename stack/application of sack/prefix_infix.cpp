#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string prefixToInfix(string prefix) {
    stack<string> s;
    int length = prefix.size();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op1 + prefix[i] + op2 + ")";
            s.push(temp);
        } else {
            s.push(string(1, prefix[i]));
        }
    }

    return s.top();
}

int main() {
    string prefix = "*+AB-CD";
    string infix = prefixToInfix(prefix);

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
