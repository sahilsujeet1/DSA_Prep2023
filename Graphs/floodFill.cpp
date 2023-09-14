#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& arr, int x, int y, int oldColor, int color) {
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = color;

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
                
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<4; i++) {
            int newX = front.first + dx[i];
            int newY = front.second + dy[i];

            if(newX >=0 && newX < arr.size() && newY >= 0 && newY < arr[newX].size() && arr[newX][newY] == oldColor && oldColor != color) {
                q.push({newX, newY});
                arr[newX][newY] = color;
            }
        }
    }

    return;
}

void dfs(vector<vector<int>>& grid, int x, int y, int old, int color) {
    grid[x][y] = color;

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && old != color && grid[newX][newY] == old) {
            dfs(grid, newX, newY, old, color);
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans = image;
    int oldColor = image[sr][sc];

    bfs(ans, sr, sc, oldColor, color);

    // map<pair<int,int>, bool> visited;
    // dfs(ans, sr, sc, oldColor, color);
    return ans;
}