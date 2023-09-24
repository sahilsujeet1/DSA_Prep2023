 #include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();

        // find the breakpoint where previous num is smaller than next. store the index
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        // if breakpoint index is -1 means decreasing sorted then reverse the array to sort in ascending
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
        } else {
        // if breakpoint found
            for(int i=n-1; i>=0; i--) {
                if(nums[i] > nums[idx]) {
                    // swap the next greater number with index number
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            // reverse the remaining right array
            reverse(nums.begin()+idx+1, nums.end());
        }

    }
};