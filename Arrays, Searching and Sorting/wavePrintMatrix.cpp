#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> &mat, int n, int m) {
    vector<int> ans;

    for(int j=0; j<m; j++) {
        if((j & 1) == 0) {
            for(int i=0; i<n; i++) {
                ans.push_back(mat[i][j]);
            }
        } else {
            for(int i=n-1; i>=0; i--) {
                ans.push_back(mat[i][j]);
            }
        }
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

    vector<int> traversal = wavePrint(matrix, n, m);

    for(auto i:traversal) {
        cout << i << " ";
    }
}