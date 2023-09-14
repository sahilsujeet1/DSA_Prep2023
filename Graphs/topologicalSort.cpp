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
    } cout << endl;
}

// Topological sort is only applicable to DAG (Directed Acyclic Graph)

void topoSortDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int n, stack<int>& ans) {
    visited[n] = true;

    for(int nbr:adj[n]) {
        if(!visited[nbr]) {
            topoSortDFS(adj, visited, nbr, ans);
        }
    }

    ans.push(n);
}

// Topological sorted graph using BFS or Kahn's Algorithm
void topoSortBFS(unordered_map<int, list<int>>& adj, int n, vector<int>& ans) {
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
        ans.push_back(front);


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
    addEdge(6,5,1,adj);
    addEdge(8,7,1,adj);
    addEdge(8,9,1,adj);
    addEdge(8,10,1,adj);

    printAdjList(adj);

    // Printing topologically sorted graph using DFS
    unordered_map<int, bool> visited;
    stack<int> sortedGraphDFS;
    
    for(int i=1; i<=v; i++) {
        if(!visited[i]) {
            topoSortDFS(adj, visited, i, sortedGraphDFS);
        }
    }

    cout << "Printing sorted graph using DFS:- " << endl;
    while(!sortedGraphDFS.empty()) {
        cout << sortedGraphDFS.top() << ", ";
        sortedGraphDFS.pop();
    } cout << endl;
    
    // Printing topologically sorted graph using BFS or Kahn's Algorithm
    vector<int> sortedGraphBFS;
    // for(int i=1; i<=v; i++)
        topoSortBFS(adj, v, sortedGraphBFS);
    cout << "Printing sorted graph using DFS:- " << endl;
    for(int i: sortedGraphBFS) {
        cout << i << ", ";
    }cout << endl;
}