#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int target) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) {
            return mid;
        } else if(mid-1 >= s && arr[mid-1] == target) {
            return mid-1;
        } else if(mid+1 <= e && arr[mid+1] == target) {
            return mid+1;
        }

        if(arr[mid] > target) {
            e = mid-2;
        } else {
            s = mid+2;
        }

        mid = s + (e-s)/2;
    }

    return -1;
}

int main() {
    int arr[] = {2,1,3,10,7,15};
    int n = 6;

    cout << binarySearch(arr, n, 34) << endl;
}