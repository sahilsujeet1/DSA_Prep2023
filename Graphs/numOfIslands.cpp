#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, map<pair<int,int>, bool>& visited, int x, int y) {
    visited[{x,y}] = true;

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0; i<4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && !visited[{newX, newY}] && grid[newX][newY] == '1') {
            dfs(grid, visited, newX, newY);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    map<pair<int,int>, bool> visited;
    int count = 0;

    for(int row=0; row<grid.size(); row++) {
        for(int col=0; col<grid[row].size(); col++) {
            if(!visited[{row,col}] && grid[row][col] == '1') {
                dfs(grid, visited, row, col);
                count++;
            }
        }
    }

    return count;
}