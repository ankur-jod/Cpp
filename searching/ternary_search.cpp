#include <iostream>
using namespace std;

int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        }
        else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        }
        else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1;
}


int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[3];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the target element: ";
    cin >> key;

    int result = ternarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
