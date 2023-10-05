#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &mat, int n, int m) {
    vector<int> ans;

    int top=0, bottom=n-1, left=0, right=m-1, count=0, totalEle = m*n;

    while(count<totalEle) {

        for(int j=left; j<=right && count<totalEle; j++) {ans.push_back(mat[top][j]); count++;}
        top++;
        for(int i=top; i<=bottom && count<totalEle; i++) {ans.push_back(mat[i][right]); count++;}
        right--;
        for(int j=right; j>=left && count<totalEle; j--) {ans.push_back(mat[bottom][j]); count++;}
        bottom--;
        for(int i=bottom; i>=top && count<totalEle; i--) {ans.push_back(mat[i][left]); count++;}
        left++;
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    int n = 3, m = 4;

    vector<int> traversal = spiralPrint(matrix, n, m);

    for(auto i:traversal) {
        cout << i << " ";
    }
}