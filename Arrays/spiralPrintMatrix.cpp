#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &mat, int n, int m) {
    vector<int> ans;

    int top=0, bottom=n-1, left=0, right=m-1;

    while(top <= bottom && left <= right) {

        for(int j=left; j<=right; j++) ans.push_back(mat[top][j]);
        top++;
        for(int i=top; i<=bottom; i++) ans.push_back(mat[i][right]);
        right--;
        for(int j=right; j>=left; j--) ans.push_back(mat[bottom][j]);
        bottom--;
        for(int i=bottom; i>=top; i--) ans.push_back(mat[i][left]);
        left++;
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int n = 4, m = 4;

    vector<int> traversal = spiralPrint(matrix, n, m);

    for(auto i:traversal) {
        cout << i << " ";
    }
}