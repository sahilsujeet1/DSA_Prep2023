#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(vector<int> arr) {
    int s = 0, e = arr.size()-1;

    while(s <= e) {
        int mid = s + (e-s)/2;

        if(s == e) return s;

        if(arr[mid] > arr[mid+1] && mid+1 <= e) {
            return mid;
        } else if(arr[mid] < arr[mid-1] && mid-1 >= s) {
            return mid-1;
        }

        if(arr[s] > arr[mid]) {
            e = mid-1;
        } else {
            s = mid+1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {7,8,9,10,2,3,4,5,6};
    // vector<int> arr = {7,8,9,10};

    cout << findPivotIndex(arr) << endl;
}