#include<iostream>
using namespace std;

// Replace with minimum element in right side
void selectionSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[5] = {4,2,56,1,3};
    selectionSort(arr, 5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << ", ";
    }
}