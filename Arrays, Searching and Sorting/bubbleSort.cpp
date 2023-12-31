#include<iostream>
using namespace std;

// sort ith largest element in each round
void bubbleSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

int main() {
    int arr[5] = {4,2,56,1,3};
    bubbleSort(arr, 5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << ", ";
    }
}