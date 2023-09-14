#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& mat, int src, map<int, bool>& visited) {
    visited[src] = true;

    for(int dest=0; dest<mat.size(); dest++) {
        if(mat[src][dest] == 1 && !visited[dest]) {
            dfs(mat, dest, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    map<int, bool> visited;
    int n = isConnected.size();
    int count = 0;

    for(int src=1; src<=n; src++) {
        if(!visited[src-1]) {
            dfs(isConnected, src-1, visited);
            count++;
        }
    }

    return count;
}