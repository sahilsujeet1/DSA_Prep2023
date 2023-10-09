//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(int n, int k, vector<int> &stalls, int target) {
        int cow = 1, pos = stalls[0];
        
        for(int i=1; i<n; i++) {
            if(stalls[i] - pos >= target) {
                cow++;
                pos = stalls[i];
            }
            if(cow == k) return true;
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s = 0, ans = -1;
        int e = stalls[n-1] - stalls[0];
        
        while(s <= e) {
            int mid = s+(e-s)/2;
            
            if(isPossible(n, k, stalls, mid)) {
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends