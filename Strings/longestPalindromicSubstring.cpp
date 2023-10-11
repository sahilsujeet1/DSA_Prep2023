#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &str, int s, int e) {
        while(s <= e) {
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(isPalindrome(s, i, j)) {
                    string sub = s.substr(i, j-i+1);
                    ans = sub.length() > ans.length() ? sub : ans;
                }
            }
        }

        return ans;
    }
};