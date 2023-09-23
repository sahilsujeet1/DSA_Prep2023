#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> data;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            data.push_back({nums[i], i});
        }

        sort(data.begin(), data.end(), cmp);
        int i=0, j=nums.size()-1;

        while(i < j) {
            if(data[i].first + data[j].first == target) {
                ans.push_back(data[i].second);
                ans.push_back(data[j].second);
                break;
            } else if(data[i].first + data[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
        
        // O(n^2) Solution follows:-
        // vector<int> ans;

        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=0; j<nums.size(); j++) {
        //         if(i != j) {
        //             int sum = nums[i] + nums[j];
        //             if(sum == target) {
        //                 ans.push_back(i);
        //                 ans.push_back(j);
        //                 return ans;
        //             }
        //         }
        //     }
        // }

        // return ans;
    }
};