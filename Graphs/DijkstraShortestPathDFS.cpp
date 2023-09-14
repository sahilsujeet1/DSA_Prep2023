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

void dijkstraShortestPath(unordered_map<int, list<pair<int,int>>>& adj, int src, int n) {
    set<pair<int,int>> st;  //{(dist, node)} in sorted or using minHeap
    vector<int> dist(n+1, INT_MAX); //distance array

    dist[src] = 0;
    st.insert({0,src});

    for(auto nbr: adj[src]) {
        int node = nbr.first;
        int nodeDist = nbr.second;

        if(dist[src] + nodeDist < dist[node]) {
            dist[node] = dist[src] + nodeDist;
            st.insert({dist[node], node});
        }
    }

    while(!st.empty()) {
        // Fetch smallest distance element from set
        pair<int,int> smallest = *st.begin();
        int node = smallest.second;
        int nodeDist = smallest.first;

        // pop smallest dist element from set
        st.erase(st.begin());

        for(auto nbr:adj[node]) {
            if(nodeDist + nbr.second < dist[nbr.first]) {
                // Search if nbr is already present in set with different distance
                auto search = st.find({dist[nbr.first], nbr.first});
                if(search != st.end()) {
                    // erase the nbr with previous distance
                    st.erase(search);
                }
                // insert nbr in set to replace
                st.insert({nodeDist + nbr.second, nbr.first});
                // update nbr distance in distance array
                dist[nbr.first] = nodeDist + nbr.second;
            }
        }
               
    }

    cout << endl << "Printing shortest distances from src to every node:-" << endl;
    for(int i=1; i<=n; i++) {
        cout << dist[i] << ", ";
    } cout << endl;
}

int main() {
    /*         7
        1--------------3
        |    11        |
      18|  /----2      |3              
        | /   6        | 
        4/----------\  |
                    6---
        5----------/
             8
    */
    unordered_map<int, list<pair<int, int>>> adj;
    int v = 6;
    addEdge(1,4,18,0,adj);
    addEdge(1,3,7,0, adj);
    addEdge(2,4,11,0,adj);
    addEdge(6,4,6,0, adj);
    addEdge(3,6,3,0, adj);
    addEdge(5,6,8,0, adj);

    printAdjList(adj);
    
    dijkstraShortestPath(adj, 2, v);
}