#include <iostream>
#include <stack>

bool arePair(char open,char close)
{
    if(open == '(' && close == ')') return true;
    else if(open == '{' && close == '}') return true;
    else if(open == '[' && close == ']') return true;
    return false;
}

bool areBalanced(std::string exp)
{
    std::stack<char>  S;
    for(int i =0;i<exp.length();i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(S.empty() || !arePair(S.top(),exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true:false;
}

int main()
{
    std::string expression;
    std::cout<<"Enter an expression:  "; 
    std::cin>>expression;
    if(areBalanced(expression))
        std::cout<<"Balanced\n";
    else
        std::cout<<"Not Balanced\n";
    return 0;
}