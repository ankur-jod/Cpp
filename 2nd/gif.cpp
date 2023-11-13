#include<iostream>
using namespace std;
int main(){
    float x,y;
    cin>>x;
    if(x<0){
        y=((int)x-1);
        cout<<y;
    }
    else{
        y=(int)x;
        cout<<y;
    }

    return 0;
}
  