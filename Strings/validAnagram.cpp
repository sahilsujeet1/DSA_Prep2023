#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int charCount[256] = {0};

        for(int i=0; i<s.length(); i++) charCount[s[i]]++;
        for(int i=0; i<t.length(); i++) charCount[t[i]]--;

        for(int i=0; i<256; i++)
            if(charCount[i] != 0)
                return false;
        return true;
    }
};