#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    
    vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    int minEffort = INT_MAX;

    dist[0][0] = 0;
    pq.push({0, {0,0}});

    while(!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int x = front.second.first;
        int y = front.second.second;
        int frontDist = front.first;

        if(x == heights.size()-1 && y == heights[0].size()-1)
            return dist[x][y];

        minEffort = min(minEffort, frontDist);

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size()) {
                int diff = abs(heights[x][y] - heights[newX][newY]);
                int newMax = max(frontDist, diff);

                if(newMax < dist[newX][newY]) {
                    pq.push({newMax, {newX, newY}});
                    dist[newX][newY] = newMax;
                }
            }
        }
    }

    return 0;

}