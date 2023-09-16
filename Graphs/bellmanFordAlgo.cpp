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
    Single source shortest path algorithm. Works on negative weights too.
    n-1 times relaxation to get the shortest path.
    Check one more time and if distances update then Cycle is present.
*/
void bellmanFordAlgo(unordered_map<int, list<pair<int, int>>>& adj, int src, int n) {
    vector<int> dist(n, INT_MAX);
    bool distUpdated;
    dist[src-1] = 0;    // -1 bcoz index starts from 0 but nodes start from 1

    for(int i=0; i<=n-1; i++) {
        distUpdated = false;
        for(auto j: adj) {
            int u = j.first - 1;    // -1 bcoz index starts from 0 but nodes start from 1
            for(auto nbr: j.second) {
                int v = nbr.first -1;    // -1 bcoz index starts from 0 but nodes start from 1
                int w = nbr.second;

                if(dist[v] > dist[u] + w && dist[u] != INT_MAX) {
                    dist[v] = dist[u] + w;
                    distUpdated = true;
                }
            }
        }

        if(i == n-1 && distUpdated) {
            cout << "Negative Cycle present" << endl;
        } else if(i == n-1 && !distUpdated) {
            cout << "Negative Cycle not present" << endl;
        }
    }

    cout << "\nPrinting shortest distances:-" << endl;
    for(auto i:dist) {
        cout << i << ", ";
    } cout << endl;

}

int main() {
    unordered_map<int, list<pair<int, int>>> adj;
    int v = 6;
    addEdge(1,4,18,1,adj);
    addEdge(1,3,7,1, adj);
    addEdge(4,2,11,1,adj);
    addEdge(4,6,6,1, adj);
    addEdge(6,3,3,1, adj);
    addEdge(6,5,8,1, adj);

    printAdjList(adj);

   bellmanFordAlgo(adj, 1, v);
}