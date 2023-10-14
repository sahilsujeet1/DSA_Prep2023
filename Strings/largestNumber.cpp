#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(string &a, string &b) {
        string s = a+b;
        string t = b+a;

        return s>t;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int i:nums) {
            snums.push_back(to_string(i));
        }

        sort(snums.begin(), snums.end(), cmp);

        if(snums[0] == "0") return "0";
        
        string ans;
        for(string str:snums) ans+= str;

        return ans;
    }
};