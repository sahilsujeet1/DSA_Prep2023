#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCoinsRec(vector<int>& coins, int target) {
        if(target < 0) return INT_MAX;
        if(target == 0) return 0;

        int n = coins.size();
        int mini = INT_MAX;

        for(int i=0; i<n; i++) {
            int coin = getCoinsRec(coins, target-coins[i]);
                cout << coin <<  endl;
            if(coin != INT_MAX) {
                mini = min(mini, coin + 1);
            }
        }
                
        return mini;
    
    }

    int getCoinsMem(vector<int>& coins, int target, vector<int>& dp) {
        if(target < 0) return INT_MAX;
        if(target == 0) return 0;

        if(dp[target] != -1) 
            return dp[target];

        int n = coins.size();
        int mini = INT_MAX;

        for(int i=0; i<n; i++) {
            int coin = getCoinsMem(coins, target-coins[i], dp);
            if(coin != INT_MAX) {
                mini = min(mini, coin + 1);
            }
        }
        dp[target] = mini;   
        return dp[target];
    }

    int getCoinsTab(vector<int>& coins, int target) {
        vector<int> dp(target+1, 0);
        int n = coins.size();
        
        for(int t=1; t<=target; t++) {
            int mini = INT_MAX;

            for(int i=0; i<n; i++) {
                if(t-coins[i] < 0) {
                    dp[t] = INT_MAX;
                } else {
                    int coin = dp[t-coins[i]];
                    if(coin != INT_MAX) {
                        mini = min(mini, coin + 1);
                    } 
                }
            }
            dp[t] = mini;   
            
        }
        return dp[target];
    }
 
    int getCoinsTab2(vector<int>& coins, int target) {
        vector<int> dp(target+1, INT_MAX);
        int n = coins.size();
        dp[0] = 0;
        
        for(int t=1; t<=target; t++) {
            for(int i=0; i<n; i++) {
                if(t >= coins[i]) {
                    int coin = dp[t-coins[i]];
                    if(coin != INT_MAX) {
                        dp[t] = min(dp[t], coin + 1);
                    }
                }
            }
            
        }
        return dp[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        // int ans = getCoinsMem(coins, amount, dp);
        int ans = getCoinsTab(coins, amount);
        // int ans = getCoinsTab2(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};