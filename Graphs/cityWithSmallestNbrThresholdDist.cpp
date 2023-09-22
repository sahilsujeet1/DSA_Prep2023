#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dijkstra(unordered_map<int, list<pair<int, int>>>& adj, int n, int src, int &threshold) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});
        int cities = 0;

        while(!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            int nodeDist = top.first;
            int node = top.second;

            if(node != src && nodeDist <= threshold)
                cities++;

            for(auto nbr: adj[node]) {
                int currDist = nodeDist + nbr.second;
                if(currDist < dist[nbr.first]) {
                    auto it = st.find({dist[nbr.first], nbr.first});
                    if(it != st.end()) st.erase(it);

                    dist[nbr.first] = currDist;
                    st.insert({currDist, nbr.first});
                }
            }
        }

        return cities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }

        int ans = INT_MAX;
        int city = 0;
        for(int i=0; i<n; i++) {
            int count = dijkstra(adj, n, i, distanceThreshold);
            if(count <= ans) {
                ans = count;
                city = i;
            }
        }

        return city;
    }
};