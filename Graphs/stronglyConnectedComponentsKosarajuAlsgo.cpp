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

void topoSort(unordered_map<int, list<int>>& adj, int src, unordered_map<int, bool>& visited, stack<int>& sorted) {
    visited[src] = true;

    for(int nbr: adj[src]) {
        if(!visited[nbr]) {
            topoSort(adj, nbr, visited, sorted);
        }
    }

    sorted.push(src);
}

void dfs(unordered_map<int, list<int>>& adj, int src, unordered_map<int, bool>& visited) {
    visited[src] = true;
    cout << src << ", ";

    for(int nbr: adj[src]) {
        if(!visited[nbr]) {
            dfs(adj, nbr, visited);
        }
    }
}

void findStronglyConnectedComponents(unordered_map<int, list<int>>& adj, int n) {
    /*
        Kosaraju Algorithm to find strongly connected components only in a directed graph
        Step1: Topological sort to find the source node
        Step2: Reverse every edge
        Step3: DFS traversal to count number of components
    */ 

   // Topological sort
   stack<int> sortedGraph;
   unordered_map<int, bool> visited;
   for(int i=0; i<n; i++) {
        if(!visited[i])
            topoSort(adj, i, visited, sortedGraph);
   }

    // Reverse every edge
    unordered_map<int, list<int>> reverseGraph;
    for(auto i: adj) {
        for(auto nbr: i.second) {
            int u = i.first;
            int v = nbr; 
            reverseGraph[v].push_back(u);
        }
    }

    // DFS Traversal of reversed graph in topological order to count components
    visited.clear();
    int count = 0;
    while(!sortedGraph.empty()) {
        int top = sortedGraph.top();
        sortedGraph.pop();

        if(!visited[top]) {
            cout << count+1 << "th SSC: "; 
            dfs(reverseGraph, top, visited);
            cout << endl;
            count++;
        } 
    }

    cout << "Total strongly connected components components: " << count << endl;
}

int main() {
    unordered_map<int, list<int>> adj;
    int v = 9;

    addEdge(0,1,1, adj);
    addEdge(1,2,1, adj);
    addEdge(2,3,1, adj);
    addEdge(3,0,1, adj);
    addEdge(2,5,1, adj);
    addEdge(5,4,1, adj);
    addEdge(4,6,1, adj);
    addEdge(6,5,1, adj);
    addEdge(6,7,1, adj);
    addEdge(7,8,1, adj);

    printAdjList(adj);
    findStronglyConnectedComponents(adj, v);
}