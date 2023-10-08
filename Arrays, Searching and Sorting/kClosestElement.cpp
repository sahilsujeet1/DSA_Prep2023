#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int x) {
        int s=0, e=arr.size()-1;
        int mid = s+(e-s)/2, ans = e;

        while(s <= e) {
            if(arr[mid] >= x) {
                ans = mid;
                e = mid-1;
            } else if(arr[mid] < x) {
                s = mid+1;
            } else {
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }

        return ans;
    }

    vector<int> bsMethod(vector<int>& arr, int k, int x) {
        int h = lowerBound(arr, x);
        int l = h-1;

        while(k--) {
            if(l < 0) {
                h++;
            } else if(h >= arr.size()) {
                l--;
            } else if(x-arr[l] > arr[h]-x) {
                h++;
            } else {
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> twoPtrMethod(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int i=0, j=n-1;

        while(j-i >= k) {
            if(x-arr[i] > arr[j]-x) {
                i++;
            } else {
                j--;
            }
        }

        return vector<int>(arr.begin()+i, arr.begin()+j+1);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return twoPtrMethod(arr, k, x);
        return bsMethod(arr, k, x);
    }
};