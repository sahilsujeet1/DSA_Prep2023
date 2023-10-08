#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bsMethod(vector<int>& nums, int k) {
        // for(auto &i:nums) i = abs(i);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int,int>> st;

        for(int i=0; i<n; i++) {
            int s = i+1, e = n-1;
            int mid = (s + e)/2;

            while(s <= e) {
                int diff = abs(nums[i] - nums[mid]);
                
                if(diff == k) {
                    st.insert({nums[i], nums[mid]});
                    break;
                } else if(diff < k) {
                    s = mid+1;
                } else {
                    e = mid-1;
                }
                mid = s + (e-s)/2;
            }
        }
        
        return st.size();
    }

    int solve(vector<int>& nums, int k) {
        set<pair<int,int>> st;
        int n = nums.size();
        int i=0, j=1;

        sort(nums.begin(), nums.end());

        while(j < n) {
            int diff = nums[j]-nums[i];
            if(diff == k) {
                st.insert({nums[j], nums[i]});
                j++; i++;
            } else if(diff < k) {
                j++;
            } else {
                i++;
            }
            if(i==j) j++;
        }

        return st.size();
    }

    int findPairs(vector<int>& nums, int k) {
        // return solve(nums, k);
        return bsMethod(nums, k);
    }
};