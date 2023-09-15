#include<bits/stdc++.h>
using namespace std;

bool topoSortBFS(map<int, list<int>>& adj, int n) {
    vector<int> ans;
    unordered_map<int, int> indegree;
    for(auto node:adj) {
        for(int nbr:node.second) {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) 
            q.push(i);
    }

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(int nbr:adj[front]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    if(ans.size() == n) return true;
    else return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    map<int, list<int>> adj;

    for(auto i:prerequisites) {
        int u = i[1];
        int v = i[0];
        adj[u].push_back(v);
    }

    return topoSortBFS(adj, numCourses);
}