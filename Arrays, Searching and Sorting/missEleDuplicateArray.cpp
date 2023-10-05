#include <bits/stdc++.h>
using namespace std;

vector<int> visitingMethod(int *arr, int n) {
    for(int i=0; i<n; i++) {
        int index = abs(arr[i])-1;
        if(arr[index] > 0) {
            arr[index] *= -1;
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0)
            ans.push_back(i+1);
    }

    return ans;
}

vector<int> sortSwap(int *arr, int n) {
    vector<int> ans;

    for(int i=0; i<n; i++) {
        int index = arr[i]-1;

        if(arr[i] != index) {
            swap(arr[i], arr[index]);
        }
    }

    for(int i=0; i<n; i++) {
        if(arr[i] != i+1)
            ans.push_back(i+1);
    }

    return ans;
}

vector<int> findMissing(int *arr, int n) {
    // Method-1: Visiting method
    // return visitingMethod(arr, n);

    // Method-2: Sorting & Swapping method
    return sortSwap(arr, n);
}

int main() {
    int n = 5;
    int arr[] = {2,4,4,4,3};

    vector<int> missing = findMissing(arr, n);

    for(auto i:missing) {
        cout << i << ", ";
    } cout << endl;
}