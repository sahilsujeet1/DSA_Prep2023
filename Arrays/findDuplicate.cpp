#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Mapping method
        // unordered_map<int,int> mp;

        // for(auto i:nums) {
        //     mp[i]++;
        //     if(mp[i] > 1) return i;
        // }

        // return 0;

        // Sort method
        // sort(nums.begin(), nums.end());
        // for(int i=0; i+1<nums.size(); i++) {
        //     if(nums[i] == nums[i+1])
        //         return nums[i];
        // }

        // return -1;

        // Negative Positioning Method
        // int ans = -1;
        // for(int i=0; i<nums.size(); i++) {
        //     int index = abs(nums[i]);

        //     if(nums[index] < 0) ans = index;

        //     nums[index] *= -1;
        // }
        // return ans;

        // Positioning at 0 index Method
        while(nums[nums[0]] != nums[0]) {
            swap(nums[nums[0]], nums[0]);
        }

        // return nums[0];

        // Binary search method

    }
};