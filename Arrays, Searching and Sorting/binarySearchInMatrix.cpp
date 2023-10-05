#include<bits/stdc++.h>
using namespace std;

/*
    arr[i][j] = col*i + j
*/

pair<int,int> findTargetIndex(vector<vector<int>> &mat, int target) {
    int row = mat.size(), col = mat[0].size();
    int totalSize = row * col;
    int s = 0, e = totalSize-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        int i = mid/col; // find ith row
        int j = mid%col; // find jth col
        int element = mat[i][j];

        if(mat[i][j] == target) {
            return {i,j};
        } else if(mat[i][j] < target) {
            s = mid+1;
        } else {
            e = mid-1;
        }

        mid = s + (e-s)/2;
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    pair<int,int> ans = findTargetIndex(mat, 7);

    cout << ans.first << ", " << ans.second << endl;
}