#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<pair<int, int>, int>> q;
    int fresh = 0;
    int time = 0;

    for(int row=0; row<grid.size(); row++) {
        for(int col=0; col<grid[row].size(); col++) {
            if(grid[row][col] == 1) fresh++;
            if(grid[row][col] == 2) q.push({{row,col}, 0});
        }
    }

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        int nodeTime = front.second;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int t = 0;
        for(int i=0; i<4; i++) {
            int newX = front.first.first + dx[i];
            int newY = front.first.second + dy[i];

            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && grid[newX][newY] == 1) {
                q.push({{newX, newY}, nodeTime+1});
                grid[newX][newY] = 2;
                fresh--;
            }
        }

        time = max(time, nodeTime);
    }

    if(fresh > 0) return -1;
    return time;
}