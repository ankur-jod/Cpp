#include<iostream>
using namespace std;

void dummy(int n){
    n++;
    cout<<"Inside dummy function: "<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Before calling dummy function: "<<n<<endl;
    dummy(n);
    cout<<"After calling dummy function: "<<n<<endl;
    return 0;
}