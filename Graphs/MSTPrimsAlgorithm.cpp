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

int getKey(vector<int>& key, vector<bool>& mst, int& n) {
    int mini = INT_MAX, index = -1;
    for(int i=0; i<n; i++) {
        if(key[i] < mini && !mst[i]) {
            mini = key[i];
            index = i;
        }
    }

    return index;
}

void primsMST(unordered_map<int, list<pair<int,int>>>& adj, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    while(true) {
        int minKey = getKey(key, mst, n);
        if(minKey == -1) break;

        mst[minKey] = true;
        
        for(auto nbr: adj[minKey]) {
            int u = minKey;
            int v = nbr.first;
            int w = nbr.second;

            if(w < key[v] && !mst[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        if(parent[i] == -1)
            continue;

        for(auto nbr: adj[i]) {
            if(parent[i] == nbr.first) {
                sum += nbr.second;
            }
        }
    }
    cout << "Prims MST Sum: " << sum << endl;
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
    int v = 5;

    addEdge(0,1,6,0, adj);
    addEdge(0,3,2,0, adj);
    addEdge(1,3,8,0, adj);
    addEdge(3,4,3,0, adj);
    addEdge(3,2,5,0, adj);
    addEdge(2,4,7,0, adj);

    printAdjList(adj);

    primsMST(adj, v);
    
}