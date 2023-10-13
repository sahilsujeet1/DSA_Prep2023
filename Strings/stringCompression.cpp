#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0, i=0, n=chars.size();

        while(i < n) {
            int j = i+1;
            while(j < n && chars[i] == chars[j])
                j++;
            
            int count = j-i;
            chars[index++] = chars[i];

            if(count > 1) {
                string cnt = to_string(count);
                for(char ch:cnt) {
                    chars[index++] = ch;
                }
            }

            i = j;
        }

        return index;
    }
};