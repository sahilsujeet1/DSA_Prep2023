#include <bits/stdc++.h>
using namespace std;

int getSumRec(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right) {
    if(left == right) return 0;

    int ans = INT_MAX;

    for(int i=left; i<right; i++) {
        ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] +
        getSumRec(arr, maxi, left, i) + getSumRec(arr, maxi, i+1, right));
    }

    return ans;
}

int getSumMem(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>>& dp) {
    if(left == right) return 0;

    if(dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;

    for(int i=left; i<right; i++) {
        ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] +
        getSumMem(arr, maxi, left, i, dp) + getSumMem(arr, maxi, i+1, right, dp));
    }

    dp[left][right] = ans;
    return dp[left][right];
}

int getSumTab(vector<int>& arr, map<pair<int, int>, int> &maxi) {
    int n = arr.size();
    vector<vector<int>>  dp(n+1, vector<int>(n+1, 0));

    for(int left=n-1; left>=0; left--) {
        for(int right=0; right<n; right++) {
            if(left >= right) continue;
            else {
                int ans = INT_MAX;

                for(int i=left; i<right; i++) {
                    ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] +
                    dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
            

        }
    }
    
    return dp[0][n-1];
}

int mctFromLeafValues(vector<int>& arr) {
    map<pair<int, int>, int> maxi;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++) {
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    // return getSumRec(arr, maxi, 0, arr.size()-1);
    // return getSumMem(arr, maxi, 0, n-1, dp);
    return getSumTab(arr, maxi);
}