#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at index i+1 (position of the pivot in the sorted array)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // element smaller than pivot are on the left
        // element greater than pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
