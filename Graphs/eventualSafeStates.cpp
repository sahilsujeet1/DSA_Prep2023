#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(vector<int> adj[], int src, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, vector<int>& ans) {
        visited[src] = true;
        dfsVisited[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!visited[nbr] && !dfsVisited[nbr]) {
                bool temp = isCyclic(adj, nbr, visited, dfsVisited, ans);
                if(temp) return true;
            } else if(visited[nbr] && dfsVisited[nbr]) {
                return true;
            }
        }
        
        ans.push_back(src);
        dfsVisited[src] = false;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> safe;
        unordered_map<int, bool> visited, dfsVisited;
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                isCyclic(adj, i, visited, dfsVisited, safe);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
        
    }
};