#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }
        
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
    
        if (arr[pos] == x)
            return pos;
    
        if (arr[pos] < x)
            low = pos + 1;
    
        else
            high = pos - 1;
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    
    int index = interpolationSearch(arr, n, x);
    
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}
