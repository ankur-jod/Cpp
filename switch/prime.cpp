#include<iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    switch (x)
    {
    case 0:
            cout<<"Not Prime";  
            break;
    case 1:
        cout<<"Not Prime";
        break;
    case 2:
        cout<<"Prime";
        break;
    default:
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                cout << "Not Prime";
                break;
            }
            else
            {
                cout << "Prime";
                break;
            }
        }
        break;
    }
    return 0;
}