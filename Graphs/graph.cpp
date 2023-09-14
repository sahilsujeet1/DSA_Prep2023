#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, int dir) {
        adj[u].push_back(v);

        if(dir == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i:adj) {
            cout << i.first << " -> ";
            for(auto j:i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    unordered_map<int, bool> visited;
    void bfs(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cout << front << ", ";

            for(auto nbr:adj[front]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    // unordered_map<int, bool> visited;
    void dfs(int node) {
        cout << node << ", ";
        visited[node] = true;

        for(auto i:adj[node]) {
            if(!visited[i]) {
                dfs(i);
            }
        }
    }

};

int main() {
    Graph g;
    int v = 10, e = 9;
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(2,4,0);
    // g.addEdge(2,5,0);
    // g.addEdge(3,6,0);
    // g.addEdge(5,6,0);
    // g.addEdge(7,8,0);
    // g.addEdge(8,9,0);
    // g.addEdge(8,10,0);

    g.addEdge(4,2,1);
    g.addEdge(3,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,5,1);
    g.addEdge(6,3,1);
    g.addEdge(6,5,1);
    g.addEdge(8,7,1);
    g.addEdge(8,9,1);
    g.addEdge(8,10,1);

    g.printAdjList();

    cout << endl << "B.F.S: " << endl;
    for(int i=1; i<=v; i++)
        if(!g.visited[i])
            g.bfs(i);
    g.visited.clear();
    
    cout << endl << "D.F.S: " << endl;
    for(int i=1; i<=v; i++)
        if(!g.visited[i])
            g.dfs(i);
    
}