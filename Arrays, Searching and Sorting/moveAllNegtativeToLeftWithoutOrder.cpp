#include <bits/stdc++.h>
using namespace std;

void moveNegatives(vector<int>& arr) {
    int l=0, h=arr.size()-1;

    while(l < h) {
        if(arr[l] < 0) {
            l++;
        } else if(arr[h] >= 0) {
            h--;
        } else {
            swap(arr[l], arr[h]);
            l++; h--;
        }
    }
}

int main() {
    vector<int> arr = {1,-8,0,6,-7,9,-9,-3,4};
    moveNegatives(arr);

    for(auto i:arr) cout << i << ", ";
}