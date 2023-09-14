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

bool isCyclicUsingBFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int n) {
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(n);
    visited[n] = true;
    parent[n] = -1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        visited[front] = true;
        
        for(int nbr: adj[front]) {
            if(!visited[nbr]) {
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = front;
            }
            else {
                if (visited[nbr] && parent[front] != nbr)
                return true;
            }
        }

    }
    return false;
}

int main() {
    unordered_map<int, list<int>> adj;
    addEdge(1,2,0, adj);
    addEdge(1,3,0, adj);
    addEdge(2,4,0, adj);
    addEdge(2,5,0, adj);
    addEdge(3,6,0, adj);
    addEdge(5,6,0, adj);
    addEdge(7,8,0, adj);
    addEdge(8,9,0, adj);
    addEdge(8,10,0,adj);

    printAdjList(adj);

    unordered_map<int, bool> visited;
    bool ans = false;
    for(int i=1; i<=10; i++) {
        if(!visited[i]) {
            ans = isCyclicUsingBFS(adj, visited, i);
            if(ans) break;
        }
    }

    cout << endl << (ans == true ? "True" : "False");
}