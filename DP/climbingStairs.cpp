#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int recMem(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return 1;
        // if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        dp[n] = recMem(n-1, dp) + recMem(n-2, dp);
        return dp[n];
    }

    int tab(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; i++) {
            if(i-2 >= 0)
                dp[i] = dp[i-1] + dp[i-2];
        }
            return dp[n];
    }

    int SO(int n) {
        int prev = 1, curr = 1, next;

        if(n == 0 || n == 1) return 1;

        for(int i=2; i<=n; i++) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }

    int climbStairs(int n) {
        int prev = 1, curr = 1, next;

        if(n == 0 || n == 1) return 1;

        for(int i=2; i<=n; i++) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;

        // vector<int> dp(n+1, -1);
        // return recMem(n, dp);
        // return SO(n);

    }
};