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

bool isCyclicUsingDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, int n) {
    visited[n] = true;
    dfsVisited[n] = true;

    for(int nbr: adj[n]) {
        if(!visited[nbr]) {
            bool isCyclic = isCyclicUsingDFS(adj, visited, dfsVisited, nbr);
            if(isCyclic) return true;
        } 
        else if(visited[nbr] && dfsVisited[nbr]) {
            return true;
        }
    }
    dfsVisited[n] = false;
    return false;
}

int main() {
    unordered_map<int, list<int>> adj;
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

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    bool ans = false;
    for(int i=1; i<=10; i++) {
        if(!visited[i]) {
            ans = isCyclicUsingDFS(adj, visited, dfsVisited,i);
            if(ans) break;
        }
    }

    cout << endl << (ans == true ? "True" : "False");
}