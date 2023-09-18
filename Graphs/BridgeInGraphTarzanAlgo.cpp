#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, int dir, unordered_map<int, list<int>>& adj) {
    adj[u].push_back(v);

    if(dir == 0) {
        adj[v].push_back(u);
    }
}

void printAdjList(unordered_map<int, list<int>>& adj) {
    for(auto i:adj) {
        cout << i.first << " -> ";
        for(auto j:i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
}

void countBridgeInGraph(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int src, int parent,
    vector<int>& time, vector<int>& low, int& timer) {
    visited[src] = true;
    time[src] = timer;
    low[src] = timer;
    timer++;

    for(int nbr: adj[src]) {
        if(nbr == parent) {
            continue;
        }
        if(!visited[nbr]) {
            // DFS call
            countBridgeInGraph(adj, visited, nbr, src, time, low, timer);
            // update low
            low[src] = min(low[src], low[nbr]);
            // check bridge
            if(time[src] < low[nbr]) {
                cout << src << "--" << nbr << endl;
            } 
        } else {
            // if node is visited and not a parent
            // update low
            low[src] = min(low[src], low[nbr]);
        }
    }
}

int main() {
    unordered_map<int, list<int>> adj;
    int v = 6;

    addEdge(0,1,0, adj);
    addEdge(0,3,0, adj);
    addEdge(2,3,0, adj);
    addEdge(2,1,0, adj);
    addEdge(3,4,0, adj);
    addEdge(5,4,0, adj);

    // printAdjList(adj);

    int timer = 1;
    vector<int> time(v);
    vector<int> low(v);
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            countBridgeInGraph(adj, visited, i, -1, time, low, timer);
        }
    }

}