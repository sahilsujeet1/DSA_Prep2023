#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        if(len1 < len2) return "";

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for(char i:t) tmap[i]++;

        int start=0, len = INT_MAX;
        int count = 0, ansIndex = -1;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            smap[ch]++;

            // valid character present in t string
            if(smap[ch] <= tmap[ch]) {
                count++;
            }

            // found the substring and now reduce the window
            if(count == len2) {

                while(smap[s[start]] > tmap[s[start]] || tmap[s[start]] == 0) {
                    // frequency decrement and start++
                    if(smap[s[start]] > tmap[s[start]])
                        smap[s[start]]--;

                    start++;
                }

                // ans update
                int windowLen = i-start+1;
                if(windowLen < len) {
                    len = windowLen;
                    ansIndex = start;
                }
            }
        }

        if(ansIndex == -1) return "";
        else return s.substr(ansIndex, len);
    }
};