#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"rows =";
    cin>>n;
    for(int i=1;i<=n;i++){
        for( int j=i;j<=i;j--){
            if(j==0) break;
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;

}