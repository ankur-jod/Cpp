#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void inputArray(int arr[], int size) {
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    inputArray(arr, size);
    printArray(arr, size);
    cout<<"Size of the array"<<sizeof(arr)/sizeof(int) <<endl;

    return 0;
}
 