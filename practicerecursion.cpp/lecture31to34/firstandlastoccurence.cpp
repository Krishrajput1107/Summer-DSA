#include <iostream>
using namespace std;

// Function to find the first occurrence of the key
int firstOccurrence(int arr[], int s, int e, int key) {
    if (s > e) {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) {
        // Check if it is the first occurrence
        if (mid == 0 || arr[mid - 1] != key) {
            return mid;
        } else {
            return firstOccurrence(arr, s, mid - 1, key);
        }
    } else if (key > arr[mid]) {
        return firstOccurrence(arr, mid + 1, e, key);
    } else {
        return firstOccurrence(arr, s, mid - 1, key);
    }
}

// Function to find the last occurrence of the key
int lastOccurrence(int arr[], int s, int e, int key) {
    if (s > e) {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key) {
        // Check if it is the last occurrence
        if (mid == e || arr[mid + 1] != key) {
            return mid;
        } else {
            return lastOccurrence(arr, mid + 1, e, key);
        }
    } else if (key > arr[mid]) {
        return lastOccurrence(arr, mid + 1, e, key);
    } else {
        return lastOccurrence(arr, s, mid - 1, key);
    }
}

int main() {
    int size;
    cout << "Enter size: " << endl;
    cin >> size;

    int arr1[size];
    cout << "Enter elements for the first array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr1[i];
    }

    int arr2[size];
    cout << "Enter elements for the second array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
    }

    int key;
    cout << "Enter element to be searched:" << endl;
    cin >> key;

    int first = firstOccurrence(arr1, 0, size - 1, key);
    int last = lastOccurrence(arr2, 0, size - 1, key);

    cout << "First occurrence in first array: " << first << endl;
    cout << "Last occurrence in second array: " << last << endl;

    return 0;
}
