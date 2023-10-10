#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for(int i=0; i<s.length(); i++) {
            int l = ans.length();
            if(l-1 >= 0 && ans[l-1] == s[i]) {
                ans.pop_back();
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};