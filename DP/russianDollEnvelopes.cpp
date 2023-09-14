#include <bits/stdc++.h>
using namespace std;

// int solveOptimal(vector<vector<int>>& arr) {
//     if(arr.size() == 0)
//         return 0;
    
//     vector<int> ans;
//     ans.push_back(arr[0][1]);

//     for(int i=1; i<arr.size(); i++) {
//         if(arr[i][0] > ans.back() && arr[i][0] > ans.back()) {
//             ans.push_back(arr[i][1]);
//         } else {
//             int index = lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
//             ans[index] = arr[i][1];
//         }
//     }

//     return ans.size();
// }
int solveOptimal(vector<vector<int>>& arr) {
    if(arr.size() == 0)
        return 0;
    
    vector<int> ans;
    
    for(int i = 0;i<arr.size();i++){
        int ele = arr[i][1];
        
        int index = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();
        
        if(index >= ans.size()) ans.push_back(ele);
        else ans[index] = ele;
    }
    
    return ans.size();
}

static bool compare(vector<int>& a, vector<int>& b) {
    if(a[0] != b[0]) {
        return a[0] < b[0];
    }

    return a[1] > b[1];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), compare);
    // return getLengthTabSO(envelopes);
    return solveOptimal(envelopes);
}

int main() {
    vector<vector<int>> envelopes = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    cout << maxEnvelopes(envelopes);
}