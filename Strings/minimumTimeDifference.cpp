#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(string time:timePoints) {
            int hr = stoi(time.substr(0,2));
            int min = stoi(time.substr(3,2));
            int minute = 60*hr + min;
            minutes.push_back(minute);
        }

        sort(minutes.begin(), minutes.end());
        int ans = INT_MAX;

        for(int i=1; i<minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i-1]);
        }

        int last = (minutes[0] + 1440) - minutes[minutes.size()-1];
        ans = min(ans, last);
        
        return ans;

    }
};