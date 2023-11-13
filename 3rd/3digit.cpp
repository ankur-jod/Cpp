#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x>=100 && x<=999)
        cout<<"Three digit number";
    else
        cout<<"not a three digit number";
    return 0;
}