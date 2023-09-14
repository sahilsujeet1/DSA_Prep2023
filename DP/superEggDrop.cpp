#include<bits/stdc++.h>
using namespace std;

int getMovesRec(int k, int n) {
    if(n == 0 || n == 1) return n;
    if(k == 1) return n;

    int ans = INT_MAX;

    for(int i=1; i<=n; i++) {
        int broken = getMovesRec(k-1, i-1);
        int notBroken = getMovesRec(k, n-i);
        int temp = max(broken, notBroken) + 1;
        ans = min(ans, temp);
    }
    

    return ans;
}

int getMovesMem(int k, int n, vector<vector<int>> &dp) {
    if(n == 0 || n == 1) return n;
    if(k == 1) return n;

    if(dp[k][n] != -1) return dp[k][n];

    int ans=INT_MAX, l=1, h=n;

    // Binary search to find the floor f.
    while(l <= h) {
        int mid = (l+h)/2;
        int broken = getMovesMem(k-1, mid-1, dp);
        int notBroken = getMovesMem(k, n-mid, dp);
        int temp = max(broken, notBroken) + 1;
        ans = min(ans, temp);

        if(broken < notBroken) {
            l = mid+1;
        } else {
            h = mid-1;
        }
    }
    dp[k][n] = ans;

    // Linear search to find the floor f
    // for(int i=1; i<=n; i++) {
    //     int broken = getMovesMem(k-1, i-1, dp);
    //     int notBroken = getMovesMem(k, n-i, dp);
    //     int temp = max(broken, notBroken) + 1;
    //     ans = min(ans, temp);
    // }
    
    return dp[k][n];
}

int getMovesTab(int k, int n) {
    vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

    for(int i=0; i<=k; i++) 
        dp[i][0] = 0, dp[i][1] = 1;

    for(int i=0; i<=n; i++) 
        dp[0][i] = 0, dp[1][i] = i;

    for(int i=2; i<=k; i++) {
        for(int j=2; j<=n; j++) {
            int ans=INT_MAX, l=1, h=j;

            // Binary search to find the floor f.
            while(l <= h) {
                int mid = (l+h)/2;
                int broken = dp[i-1][mid-1];
                int notBroken = dp[i][j-mid];
                int temp = max(broken, notBroken) + 1;
                ans = min(ans, temp);

                if(broken < notBroken) {
                    l = mid+1;
                } else {
                    h = mid-1;
                }
            }
            dp[i][j] = ans;
        }
    }

    

    // Linear search to find the floor f
    // for(int i=1; i<=n; i++) {
    //     int broken = getMovesMem(k-1, i-1, dp);
    //     int notBroken = getMovesMem(k, n-i, dp);
    //     int temp = max(broken, notBroken) + 1;
    //     ans = min(ans, temp);
    // }
    
    return dp[k][n];
}

int superEggDrop(int k, int n) {
    // vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
    
    // return getMovesRec(k, n);
    // return getMovesMem(k, n, dp);
    return getMovesTab(k, n);
}