#include<bits/stdc++.h>
using namespace std;

long long findWaysRec(int n, int k) {
    int MOD = 1000000007;
    if(n == 1) return k;
    if(n == 2) 
        return (k + k*(k-1));
    
    int ans = ((findWaysRec(n-2, k) + findWaysRec(n-1, k)) * (k-1)) % MOD;
    return ans;
}

long long findWaysMem(int n, int k, vector<long long>& dp) {
    int MOD = 1000000007;
    
    if(n == 1) return k;
    if(n == 2) 
        return (k + k*(k-1));
    if(dp[n] != -1) return dp[n];

    dp[n] = ((findWaysMem(n-2, k, dp) + findWaysMem(n-1, k, dp)) * (k-1)) % MOD;
    return dp[n];
}

long long findWaysTab(int n, int k) {
    vector<long long> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k + k*(k-1);
    
    int MOD = 1000000007;
    for(int i=3; i<=n; i++) {
        dp[i] = ((dp[i-2] + dp[i-1]) * (k-1)) % MOD;
    }
    
    return dp[n];
}

long long countWays(int n, int k){
    // code here
    vector<long long> dp(n+1, -1);
    
    // return findWaysRec(n, k);
    // return findWaysMem(n, k, dp);
    return findWaysTab(n, k);
}

int main() {
    int n = 79, k = 53;

    cout << countWays(n, k) << endl;
}