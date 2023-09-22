#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if(rank[u] > rank[v]) {
            parent[v] = u;
            rank[u]++;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++) parent[i] = i;

        unordered_map<string, int> mp;
        for(int i=0; i<n; i++) {
            vector<string> acc = accounts[i];
            for(int j=1; j<acc.size(); j++) {
                string& mail = acc[j];
                auto it = mp.find(mail);
                if(it == mp.end()) mp[mail] = i;
                else unionSet(i, it->second, parent, rank);
            }
        }

        unordered_map<int, set<string>> preAns;
        for(auto i:mp) {
            string email = i.first;
            int node = i.second;
            node = findParent(parent, node);

            preAns[node].insert(email);
        }

        vector<vector<string>> ans;
        for(auto i:preAns) {
            int index = i.first;
            set<string> st = i.second;

            vector<string> emails;
            emails.push_back(accounts[index][0]);
            for(auto j:st) emails.push_back(j);
            ans.push_back(emails);
        }

        return ans;
    }
};