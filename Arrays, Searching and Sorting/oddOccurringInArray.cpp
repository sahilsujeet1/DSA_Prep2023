#include<iostream>
using namespace std;

int oddElement(int *arr, int n) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(s == e) {
            return arr[s];
        }

        if(mid%2 == 0) {
            if(arr[mid] == arr[mid+1]) {
                s = mid+2;
            } else {
                e = mid;
            }
        } else {
            if(arr[mid] == arr[mid-1]) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        mid = s+(e-s)/2;
    }
    
    return -1;
}

int main() {
    int arr[] = {1,1,2,2,3,3,4,4,3,5,5,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << oddElement(arr, n) << endl;
}