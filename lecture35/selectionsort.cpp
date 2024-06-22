#include <iostream>
using namespace std;

void selectionSort(int arr[], int size, int start = 0) {
    // Base case
    if (start >= size - 1) {
        return;
    }

    // Find the minimum element in the unsorted part of the array
    int minIndex = start;
    for (int j = start + 1; j < size; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    // Swap the found minimum element with the first element
    swap(arr[minIndex], arr[start]);

    // Recursively sort the remaining part of the array
    selectionSort(arr, size, start + 1);
}

int main() {
    int size;
    cout << "Enter size: " << endl;
    cin >> size;

    int arr[size];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
