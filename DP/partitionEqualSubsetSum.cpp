#include <bits/stdc++.h>
using namespace std;

bool isPossibleRec(vector<int> nums, int i, int target) {
    int n = nums.size();
    if(i >= n || target < 0) return 0;
    if(target == 0) return true;

    bool inc = isPossibleRec(nums, i+1, target-nums[i]); 
    bool exc = isPossibleRec(nums, i+1, target); 

    return (inc || exc);
}

bool isPossibleMem(vector<int> &nums, int i, int target, vector<vector<int>>& dp) {
    int n = nums.size();
    if(i >= n || target < 0) return false;
    if(target == 0) return true;

    if(dp[i][target] != -1) return dp[i][target];

    bool inc = isPossibleMem(nums, i+1, target-nums[i], dp); 
    bool exc = isPossibleMem(nums, i+1, target, dp); 

    dp[i][target] = (inc || exc);
    return dp[i][target];
}

bool isPossibleTab(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i=0; i<=n; i++) {
        dp[i][0] = 1;
    }

    for(int i=n-1; i>=0; i--) {
        for(int t=0; t<=target; t++) {
            bool inc = 0;
            if(t-nums[i] >= 0)
                inc = dp[i+1][t-nums[i]]; 
            bool exc = dp[i+1][t]; 
            dp[i][t] = (inc || exc);
        }
    }

    return dp[0][target];
}

bool isPossibleTabSO(vector<int> &nums, int target) {
    int n = nums.size();

    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    // for(int i=0; i<=n; i++) {
    //     dp[i][0] = 1;
    // }
    next[0] = 1; 
    // becuase the upper loop proceeds towards end. So it has to be last row when it ends and hence last should next and its previous should be curr

    for(int i=n-1; i>=0; i--) {
        for(int t=0; t<=target; t++) {
            bool inc = 0;
            if(t-nums[i] >= 0)
                inc = next[t-nums[i]]; 
            bool exc = next[t]; 
            curr[t] = (inc || exc);
        }
        next = curr;
    }

    return next[target];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i:nums) sum+= i;
    if(sum & 1)
        return false;

    int target = sum/2;
    vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));

    // int ans = isPossibleRec(nums, 0, target);
    // int ans = isPossibleMem(nums, 0, target, dp);
    // int ans = isPossibleTab(nums, target);
    int ans = isPossibleTabSO(nums, target);


    return ans;
}

int main() {
    vector<int> num{9,67,15,64,51,53,21,1,98,84,70,53,96,90,57,39,12,21,13,19,70,2,2,58,57,59,67,83,49,86,45,53,68,57,84,87,38,97,71,72,13,57,40,100,2,19,24,90,1,45,34,34,55,97,65,73,58,23,27,1,8,6,91,72,15,3,97,30,36,44,99,19,88,63,17,57,37,39,6,69,22,55,65,89,44,94,41,17,6,12,20,31,53,80,6,24,38,45,8,24};
    cout << (canPartition(num) == true ?  "True" : "False");
}