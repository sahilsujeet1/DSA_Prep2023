#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int e) {
        while(i<=e) {
            if(s[i++] != s[e--])
                return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0, j=s.length()-1;

        while(i < j) {
            if(s[i] != s[j]) {
                return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
            } else {
                i++; j--;
            }
        }

        return true;
    }
};