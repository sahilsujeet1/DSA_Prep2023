#include <bits/stdc++.h>
using namespace std;

int findMinAmountRec(int s, int e) {
    if(s >= e) return 0;

    int ans = INT_MAX;

    for(int i=s; i<=e; i++) {
        int left = findMinAmountRec(s,i-1);
        int right = findMinAmountRec(i+1, e);
        ans = min(ans, i + max(left, right));
    }
        
    return ans;
}

int findMinAmountMem(int s, int e, vector<vector<int>>& dp) {
    if(s >= e) return 0;

    if(dp[s][e] != -1) return dp[s][e];

    int ans = INT_MAX;

    for(int i=s; i<=e; i++) {
        int left = findMinAmountMem(s,i-1, dp);
        int right = findMinAmountMem(i+1, e, dp);
        ans = min(ans, i + max(left, right));
    }
    dp[s][e] = ans;
    return dp[s][e];
}

int findMinAmountTab(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int a=n; a>=1; a--) {
        for(int b=1; b<=n; b++) {
            if(a>=b) continue;
            else {
                int ans = INT_MAX;

                for(int i=a; i<=b; i++) {
                    int left = dp[a][i-1];
                    int right = dp[i+1][b];
                    ans = min(ans, i + max(left, right));
                }
                dp[a][b] = ans;
            }
        }
    }

    return dp[1][n];
}

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // int ans = findMinAmountRec(1, n);
    // int ans = findMinAmountMem(1, n, dp);
    int ans = findMinAmountTab(n);
    return ans;
}

int main() {
    int n = 20;
    cout << getMoneyAmount(n) << endl;
}