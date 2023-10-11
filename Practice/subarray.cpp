#include<bits/stdc++.h>
using namespace std;

int getValue(vector<int> &arr, int i, int j) {
    int count = 0;


    // unordered_map<int,int> freq;
    // while(i <= j) {
    //     freq[arr[i++]]++;
    // }
    
    // for(auto f:freq) {
    //     if(f.second > 1)
    //         count++;
    // }
    
    return count;
}

int ValueOfSubarrays(int n, vector<int> &arr) {
    // code here
    int MOD = 1000000007;
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            ans += getValue(arr, i, j) % MOD;
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << endl << endl << ValueOfSubarrays(n, arr) << endl;
}