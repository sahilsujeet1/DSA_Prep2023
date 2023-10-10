#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int hash[256] = {0};
        bool isMapped[256] = {false};

        for(int i=0; i<n; i++) {
            if(hash[s[i]] == 0 && !isMapped[t[i]]) {
                hash[s[i]] = t[i];
                isMapped[t[i]] = true;
            }
        }

        for(int i=0; i<n; i++) {
            if(hash[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};