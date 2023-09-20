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
        if(rank[u] > rank[v]) {
            parent[v] = u;
            rank[u]++;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        int extraEdge = 0, compNum = 0;

        for(int i=0; i<n; i++) 
            parent[i] = i;

        for(auto conn: connections) {
            int u = conn[0];
            int v = conn[1];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if(u != v) {
                unionSet(u, v, parent, rank);
            } else {
                extraEdge++;
            }
        }

        for(int i=0; i<n; i++) {
            if(parent[i] == i)
                compNum++;
        }

        int ans = compNum - 1;
        
        if(extraEdge >= ans) return ans;
        return -1;
    }
};