#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter the character : ";
    cin>>ch;
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122))
        cout<<"Alphabet";
    else
        cout<<"Not Alphabet";
    return 0;
}