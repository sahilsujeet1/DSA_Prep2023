#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0, j=0, sum=0;

        while(j < nums.size()) {
            sum += nums[j];

            while(sum >= target) {
                /*
                    reduce the window size by subtracting the removed num from start, forwarding the start, and update window length
                */
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        if(ans == INT_MAX) return 0;
        return ans;
    }
};