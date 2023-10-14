#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> str(numRows);
        int n = s.length(), row=0;

        bool topToBottom = true;

        for(int i=0; i<n; i++) {
            if(topToBottom) {
                if(row < numRows) {
                    str[row++].push_back(s[i]);
                    if(row == numRows) {
                        row = row-2;
                        topToBottom = false;
                    }
                }
            } else {
                if(row >= 0) {
                    str[row--].push_back(s[i]);
                    if(row < 0) {
                        row = 1;
                        topToBottom = true;
                    }
                }
            }
        }

        string ans;
        for(string i:str) {
            ans += i;
        }

        return ans;
    }
};