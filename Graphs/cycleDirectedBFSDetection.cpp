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

void topoSortBFS(unordered_map<int, list<int>>& adj, int n, int& count) {
    unordered_map<int, int> indegree;
    for(auto node:adj) {
        for(int nbr:node.second) {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) 
            q.push(i);
    }

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        count++;

        for(int nbr:adj[front]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
}

int main() {
    unordered_map<int, list<int>> adj;
    int v = 10;
    addEdge(1,2,1,adj);
    addEdge(3,1,1,adj);
    addEdge(4,2,1,adj);
    addEdge(2,5,1,adj);
    addEdge(6,3,1,adj);
    addEdge(5,6,1,adj);
    addEdge(8,7,1,adj);
    addEdge(8,9,1,adj);
    addEdge(8,10,1,adj);

    printAdjList(adj);

    // Topological sort is only applicable with Directed Ayclic Graph. If complete sorting fails then it is not a DAG.
    // Count denotes the number of sorted nodes in graph.
    // If count is not equal to number of vertices of graph, then topological sorting failed and hence it is not Cyclic.

    int count = 0;
    topoSortBFS(adj, v, count);

    cout << endl << (count != v ? "Graph is cyclic" : "Graph is acyclic");
}