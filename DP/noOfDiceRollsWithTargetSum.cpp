#include<bits/stdc++.h>
using namespace std;

int getRollsRec(int n, int k, int target) {
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    int ans = 0;
    for(int i=1; i<=k; i++) {
        ans += getRollsRec(n-1, k, target-i);
    } 
    
    return ans;
}

int getRollsMem(int n, int k, int target, vector<vector<int>>& dp) {
    if(n == 0 && target == 0) return 1;
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;

    if(dp[n][target] != -1) return dp[n][target];

    long long int MOD = 1000000007;
    int ans = 0;
    for(int i=1; i<=k; i++) {
        int rec = 0;
        if(target-i >= 0)
            rec = getRollsMem(n-1, k, target-i, dp);
        ans = (ans + rec)%MOD;
    } 
    
    dp[n][target] = ans;
    return dp[n][target];
}

int getRollsTab(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;

    long long int MOD = 1000000007;

    for(int d=1; d<=n; d++) {
        for(int t=target; t>=0; t--) {
            int ans = 0;
            for(int i=1; i<=k; i++) {
                int rec = 0;
                if(t-i >= 0)
                    rec = dp[d-1][t-i]%MOD;
                ans = (ans%MOD + rec%MOD)%MOD;
            }
            dp[d][t] = ans;
        }
    }

    return dp[n][target];
}

int getRollsTabSO(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    prev[0] = 1;

    long long int MOD = 1000000007;

    for(int d=1; d<=n; d++) {
        for(int t=target; t>=0; t--) {
            int ans = 0;
            for(int i=1; i<=k; i++) {
                int rec = 0;
                if(t-i >= 0)
                    rec = prev[t-i]%MOD;
                ans = (ans%MOD + rec%MOD)%MOD;
            }
            curr[t] = ans;
        }
        prev = curr;
    }

    return prev[target];
}

int numRollsToTarget(int n, int k, int target) {
    // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

    // return getRollsRec(n, k, target);
    // return getRollsMem(n, k, target, dp);
    // return getRollsTab(n, k, target);
    return getRollsTabSO(n, k, target);
}

int main() {
    int n = 3;
    int k = 6;
    int target = 13;

    cout << numRollsToTarget(n,k,target);
}