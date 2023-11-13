
// Error Code

#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x == 1 || x == 0)
    {
        cout << "Not Prime";
    }
    else if (x == 2)
    {
        cout << "Prime";
    }
    else{
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
    }
    return 0;
}
