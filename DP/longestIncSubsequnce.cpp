#include <bits/stdc++.h>
using namespace std;

int getLengthRec(vector<int>& nums, int curr, int prev) {
    int n = nums.size();
    if(curr >= n) return 0;

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + getLengthRec(nums, curr+1, curr);
    
    int exclude = getLengthRec(nums, curr+1, prev);
    int ans = max(include, exclude);
    return ans;
    
}

int getLengthMem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
    int n = nums.size();
    if(curr >= n) return 0;

    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev])
        include = 1 + getLengthMem(nums, curr+1, curr, dp);
    
    int exclude = getLengthMem(nums, curr+1, prev, dp);
    dp[curr][prev+1] = max(include, exclude);
    return dp[curr][prev+1];
    
}

int getLengthTab(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr+1][curr+1];
            
            int exclude = dp[curr+1][prev+1];
            dp[curr][prev+1] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int getLengthTabSO(vector<int>& nums) {
    int n = nums.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0;
            if(prev == -1 || nums[curr] > nums[prev])
                include = 1 + nextRow[curr+1];
            
            int exclude = nextRow[prev+1];
            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }

    return nextRow[0];
}

int solveOptimal(vector<int>& arr) {
    if(arr.size() == 0)
        return 0;
    
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}

int lengthOfLIS(vector<int>& nums) {
    // int prev = -1, curr = 0, n = nums.size();
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    // return getLengthRec(nums, curr, prev);
    // return getLengthMem(nums, curr, prev, dp);
    // return getLengthTab(nums);
    // return getLengthTabSO(nums);
    return solveOptimal(nums);
}