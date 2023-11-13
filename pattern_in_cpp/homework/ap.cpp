#include <iostream>
using namespace std;

int ap(int a, int d, int n) {
    return (n * (2 * a + (n - 1) * d)) / 2;
}

int main(){
    int a, d, n;
    cout << "Enter the first term of the AP: ";
    cin >> a;
    cout << "Enter the difference of the AP: ";
    cin >> d;
    cout << "Enter the number of terms in the AP: ";
    cin >> n;
    cout << "The sum of the AP is " << ap(a, d, n) << endl;
    return 0;
}
