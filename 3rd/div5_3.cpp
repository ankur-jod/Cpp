#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x%3==0 || x%5==0)
        cout<<"Div by 5 or 3";    
    else
        cout<<"Not";
 
    return 0;
}