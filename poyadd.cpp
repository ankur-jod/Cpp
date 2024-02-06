#include <iostream>
using namespace std;

void add(int poly1[], int poly2[], int poly3[], int m, int n)
{
    int i;

    if(m>n)
    {
        for(i=0;i<n;i++)
            poly3[i] = poly1[i] + poly2[i];
        for(i=n;i<m;i++)
            poly3[i] = poly1[i];
    }
    else
    {
        for(i=0;i<m;i++)
            poly3[i] = poly1[i] + poly2[i];
        for(i=m;i<n;i++)
            poly3[i] = poly2[i];    
    }
}

int main()
{
    int poly1[10], poly2[10], poly3[10];
    int m, n, i;

    cout << "Enter the degree of polynomial 1: ";
    cin >> m;
    cout << "Enter the coefficients of polynomial 1: ";
    for(i=0; i<=m; i++)
        cin >> poly1[i];

    cout << "Enter the degree of polynomial 2: ";
    cin >> n;
    cout << "Enter the coefficients of polynomial 2: ";
    for(i=0; i<=n; i++)
        cin >> poly2[i];

    add(poly1, poly2, poly3, m+1, n+1);

    cout << "The sum of the polynomials is: ";
    for(i=0; i<=max(m,n); i++)
        cout << poly3[i] << " ";
    cout << endl; 

    system("pause"); 
    return 0;
} 