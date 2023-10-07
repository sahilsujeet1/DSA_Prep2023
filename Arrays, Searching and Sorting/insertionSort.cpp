#include<iostream>
using namespace std;

// Place every element to its right position in left
/*
    Step1: Compare prev
    Step2: If greater-> Shift, else break loop
    Step3: Copy original element to correct place
*/
void insertionSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        int temp = arr[i];
        int j;
        for(j=i-1; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else 
                break;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[5] = {4,2,56,1,3};
    insertionSort(arr, 5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << ", ";
    }
}