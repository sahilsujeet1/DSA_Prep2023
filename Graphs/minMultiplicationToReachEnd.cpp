
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int MOD = 100000;
        queue<int> q;
        vector<int> ans(100000, -1);  // stores step count for every multiple ans
        
        q.push(start);
        ans[start] = 0;
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if(front == end) return ans[end];
            
            for(int i: arr) {
                int temp = front * i % MOD;
                if(ans[temp] == -1) {
                    ans[temp] = ans[front] + 1;
                    q.push(temp);
                }
            }
        }
        
        return -1;
    }
};
