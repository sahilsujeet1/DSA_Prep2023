#include <bits/stdc++.h>
using namespace std;

vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
{
    // code here
    vector<int> ans;
    
    if(n==1) for(int j=0; j<m; j++) ans.push_back(mat[0][j]);
    else if(m==1) for(int i=0; i<n; i++) ans.push_back(mat[i][0]);
    else {
        for(int j=0; j<m; j++) ans.push_back(mat[0][j]);
        for(int i=1; i<n; i++) ans.push_back(mat[i][m-1]);
        for(int j=m-2; j>=0; j--) ans.push_back(mat[n-1][j]);
        for(int i=n-2; i>=1; i--) ans.push_back(mat[i][0]);
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

    vector<int> traversal = boundaryTraversal(matrix, n, m);

    for(auto i:traversal) {
        cout << i << " ";
    }
}