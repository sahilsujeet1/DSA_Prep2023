#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, int wt, int dir, unordered_map<int, list<pair<int, int>>>& adj) {
    adj[u].push_back({v,wt});

    if(dir == 0) {
        adj[v].push_back({u,wt});
    }
}

void printAdjList(unordered_map<int, list<pair<int, int>>>& adj) {
    for(auto i:adj) {
        cout << i.first << " -> ";
        for(auto j:i.second) {
            cout << "(" << j.first << ", " << j.second << "), ";
        }
        cout << endl;
    } cout << endl;
}

/*
    Distance from each node to every node via a helper node
    1 -> 6 = 1 -> 2 -> 6
             1 -> 3 -> 6 etc
*/
void floydWarshallAlgo(unordered_map<int, list<pair<int, int>>>& adj, int n) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(int i=0; i<n; i++) {
        dist[i][i] = 0;         // distance from source node to same node = 0
    }

    for(auto i:adj) {           // Distances from given src node to destination node in distance array
        int u = i.first;
        for(auto nbr: i.second) {
            int v = nbr.first;
            int w = nbr.second;
            dist[u][v] = w;
        }
    }

    for(int helper=0; helper<n; helper++) {
        for(int src=0; src<n; src++) {
            for(int dest=0; dest<n; dest++) {
                dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
            }
        }
    }

    cout << "Printing distances:-" << endl;
    for(auto i:dist) {
        for(auto j:i) {
            cout << j << " ";
        }cout << endl;
    } cout << endl;

}

int main() {
    unordered_map<int, list<pair<int, int>>> adj;
    int v = 4;
    // addEdge(0,3,18,1,adj);
    // addEdge(0,2,7,1, adj);
    // addEdge(3,1,11,1,adj);
    // addEdge(3,5,6,1, adj);
    // addEdge(5,2,3,1, adj);
    // addEdge(5,4,8,1, adj);

    addEdge(0,3,5,1,adj);
    addEdge(0,1,3,1, adj);
    addEdge(1,0,2,1, adj);
    addEdge(1,3,4,1, adj);
    addEdge(2,1,1,1, adj);
    addEdge(3,2,2,1, adj);

    printAdjList(adj);

   floydWarshallAlgo(adj, v);
}