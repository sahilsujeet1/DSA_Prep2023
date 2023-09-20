#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<vector<string>, int>> q;
        vector<vector<string>> ans;
        vector<string> toRemove;
        int prevLevel = -1;

        q.push({{beginWord}, 0});

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            vector<string> seq = front.first;
            string word = seq[seq.size()-1];
            int level = front.second;

            if(level != prevLevel) {
                for(string i:toRemove) st.erase(i);
                prevLevel = level;
                toRemove.clear();
            }

            if(word == endWord) ans.push_back(seq);

            for(int i=0; i<word.size(); i++) {
                char prev = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        vector<string> temp = seq;
                        temp.push_back(word);
                        q.push({temp, level+1});
                        toRemove.push_back(word);
                    }
                }
                word[i] = prev;
            }            
        }

        return ans;
    }
};