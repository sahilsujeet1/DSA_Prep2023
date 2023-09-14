#include <bits/stdc++.h>
using namespace std;

int getLengthRec(string a, string b, int i, int j) {
    if(i==a.length()) return 0;
    if(j==b.length()) return 0;

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + getLengthRec(a, b, i+1, j+1);
    } else {
        ans = max(getLengthRec(a, b, i+1, j), getLengthRec(a, b, i, j+1));
    }

    return ans;
}

int getLengthMem(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
    if(i==a.length()) return 0;
    if(j==b.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]) {
        ans = 1 + getLengthMem(a, b, i+1, j+1, dp);
    } else {
        ans = max(getLengthMem(a, b, i+1, j, dp), getLengthMem(a, b, i, j+1, dp));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int getLengthTab(string a, string b) {
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=a.length()-1; i>=0; i--) {
        for(int j=b.length()-1; j>=0; j--) {
            int ans = 0;
            if(a[i] == b[j]) {
                ans = 1 + dp[i+1][j+1];
            } else {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    int i=0, j=0;
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    // return getLengthRec(text1, text2, i, j);
    // return getLengthMem(text1, text2, i, j, dp);
    return getLengthTab(text1, text2);
}