#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, int w, int dir, unordered_map<int, list<pair<int,int>>>& adj) {
    adj[u].push_back({v,w});

    if(dir == 0) {
        adj[v].push_back({u,w});
    }
}

void printAdjList(unordered_map<int, list<pair<int,int>>>& adj) {
    for(auto i:adj) {
        cout << i.first << " -> ";
        for(auto j:i.second) {
            cout << "(" << j.first << ", " << j.second << "), ";
        }
        cout << endl;
    }
}

int findParent(vector<int>& parent, int node) {
    if(parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void mergeCompSetUnion(int u, int v, vector<int>& parent, vector<int>& rank) {
    // u = findParent(parent, u);
    // v = findParent(parent, v);

    // cout << "Inside for mergeCompSetUnion: " << endl;
    // cout << "Parent(u): " << u << ", Parent(v): " << v << endl;

    if(rank[u] > rank[v]) {
        parent[v] = u;
        rank[u]++;
    } else {
        parent[u] = v;
        rank[v]++;
    }
}

void mstKruskalAlgo(unordered_map<int, list<pair<int, int>>>& adj, int n) {
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
    parent[0] = -1;

    vector<vector<int>> edges;

    for(auto edge: adj) {
        for(auto nbr: edge.second) {
            int u = edge.first;
            int v = nbr.first;
            int w = nbr.second;

            edges.push_back({w,u,v});
        }
    }

    sort(edges.begin(), edges.end());

    int sum = 0;

    for(auto edge: edges) {
        int u = findParent(parent, edge[1]);
        int v = findParent(parent, edge[2]);
        int w = edge[0];

        // cout << "Inside for loop: " << endl;
        // cout << "Parent(" << edge[1] << "): " << u << ", Parent(" << edge[2] << "): " << v << endl;
        if(u != v) {
            mergeCompSetUnion(u, v, parent, rank);
            sum += w;
            // Kruskal MST
            // cout << edge[1] << "---" << edge[2] << " = " << edge[0] << endl;
        }
    }

    cout << "MST Sum: " << sum << endl;
}

int main() {
    /*        
                2          3
            0--------3----------4
            |     8 /|5        /
           6| /----/ | /------/ 7
            |/       |/
            1        2


    */
    unordered_map<int, list<pair<int, int>>> adj;
    int v = 6;

    addEdge(1,4,1,0, adj);
    addEdge(1,5,4,0, adj);
    addEdge(1,2,2,0, adj);
    addEdge(5,4,9,0, adj);
    addEdge(4,3,5,0, adj);
    addEdge(4,2,3,0, adj);
    addEdge(2,3,3,0, adj);
    addEdge(2,6,7,0, adj);
    addEdge(3,6,8,0, adj);
    printAdjList(adj);

    mstKruskalAlgo(adj, v);
    
}