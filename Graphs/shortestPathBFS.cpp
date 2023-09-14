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

void shortestPathBFS(unordered_map<int, list<int>> adj, int src, int dest) {
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    stack<int> ans;

    visited[src] = true;
    parent[src] = -1;
    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto nbr:adj[front]) {
            if(!visited[nbr]) {
                q.push(nbr);
                parent[nbr] = front;
                visited[nbr] = true;
            }
        }
    }

    while(dest != -1) {
        ans.push(dest);
        dest = parent[dest];
    }

    cout << endl << "Printing path: " << endl;
    while(!ans.empty()) {
        cout << ans.top() << " -> ";
        ans.pop();
    } cout << endl;

}

int main() {
    /*
        1--------------3
        |              |
        |  /----2      |              
        | /            | 
        4/----------\  |
                    6---
        5----------/
    
    */
    unordered_map<int, list<int>> adj;
    addEdge(1,4,0, adj);
    addEdge(1,3,0, adj);
    addEdge(2,4,0, adj);
    addEdge(6,4,0, adj);
    addEdge(3,6,0, adj);
    addEdge(5,6,0, adj);

    // printAdjList(adj);

    shortestPathBFS(adj, 1,3);
    shortestPathBFS(adj, 1,2);
}