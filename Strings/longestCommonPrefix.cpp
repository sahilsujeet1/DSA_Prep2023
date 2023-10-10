#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), i=0;
        string ans = "";
        
        while(true) {
            char curr = 0;

            for(string str:strs) {
                if(i >= str.size()) {
                    curr = 0;
                    break;
                }

                if(curr == 0) curr = str[i];
                else if(curr != str[i]) {
                    curr = 0;
                    break;
                }
            }

            if(curr == 0) break;
            ans += curr;
            i++;
        }

        return ans;
    }
};