#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::array<int, 256> getHash(string str) {
        std::array<int, 256> hash = {0};
        for(auto ch:str) hash[ch]++;

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int, 256>, vector<string>> mp;

        for(auto str:strs) {
            mp[getHash(str)].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto i:mp) {
            vector<string> group;
            for(auto j:i.second) {
                group.push_back(j);
            }
            ans.push_back(group);
        }

        return ans;
    }
};