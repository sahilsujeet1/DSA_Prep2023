#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";

        for(int i=0; i<s.length(); i++) {
           char ch = tolower(s[i]);
           if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                a += ch;
        }

        int i=0, e=a.length()-1;
        while(i < e) {
            if(a[i++] != a[e--])
                return false;
        }

        return true;
    }
};