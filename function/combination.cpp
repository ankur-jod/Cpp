#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;
    cout << "The combination of " << n << " choose " << r << " is " << combination(n, r) << endl;
    return 0;
}
