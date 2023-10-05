#include<bits/stdc++.h>
using namespace std;

int firstRepeated(int arr[], int n) {
    // code here
    
    // Method-1: O(n^2) time complexity. Matching every element with other.
    // for(int i=0; i<n; i++) {
    //     bool isRepeated = false;
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[i] == arr[j]) {
    //             isRepeated = true;
    //             return i+1;
    //         }
    //     }
    // }
    // return -1;
    
    // Method-2: O(n) time complexity using hashmaps
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }

    for(int i=0; i<n; i++) {
        if(mp[arr[i]] > 1)
            return i+1;
    }
    
    return -1;
}

int main() {
    int arr[] = {5,3,4,8,45,1,8,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << firstRepeated(arr, n) << endl;
}