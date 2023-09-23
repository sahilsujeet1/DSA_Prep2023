#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[i] > nums[dq.back()])  // remove small number index from front if larger number found
                dq.pop_back();

            dq.push_back(i);  // maximum number index in front
        }

        ans.push_back(nums[dq.front()]);

        for(int i=k; i<nums.size(); i++) {
            // removal
            while(!dq.empty() && i-k >= dq.front())
                dq.pop_front();

            // addition
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);

            // store max num
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};