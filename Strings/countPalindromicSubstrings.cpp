#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(string s, int i, int j) {
        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for(int i=0; i<s.length(); i++) {
            int oddCount = getCount(s, i, i);
            int evenCount = getCount(s, i, i+1);

            count += oddCount + evenCount;
        }

        return count;
    }
};