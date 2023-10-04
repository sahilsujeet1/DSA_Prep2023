#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findPivotIndex(vector<int>& arr) {
        int s = 0, e = arr.size()-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            if(s == e) return s;

            if(mid+1 <= e && arr[mid] > arr[mid+1]) {
                return mid;
            } 
            if(mid-1 >= s && arr[mid-1] > arr[mid]) {
                return mid-1;
            }

            if(arr[s] > arr[mid]) {
                e = mid-1;
            } else {
                s = mid+1;
            }

            mid = s+(e-s)/2;
        }

        return -1;
    }

    int binarySearch(vector<int>& arr, int s, int e, int t) {
        int mid = s + (e-s)/2;

        while(s <= e) {
            if(arr[mid] == t) {
                return mid;
            } 
            if(arr[mid] < t) {
                s = mid+1;
            } else {
                e = mid-1;
            }

            mid = s+(e-s)/2;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // Find pivot then check in left sorted array or right sorted array

        int pivot = findPivotIndex(nums);
        int ans = 0;

        if(target >= nums[0] && target <= nums[pivot]) {
            ans = binarySearch(nums, 0, pivot, target);
        } else {
            ans = binarySearch(nums, pivot+1, nums.size()-1, target);
        }

        return ans;
    }
};