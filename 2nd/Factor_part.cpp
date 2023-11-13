#include<iostream>
using namespace std;
int main(){
    float x,y;
    cin>>x;
    if(x<0){
        y=x-((int)x-1);
        cout<<y;
    }
    else{
        y=x-(int)x;
        cout<<y;
    }

    return 0;
}
  