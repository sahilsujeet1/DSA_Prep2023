#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<long long int> &trees, long long int n, long long int m, long long int mid) {
    long long int wood = 0;
    for(int i=0; i<n; i++) {
        if(trees[i] > mid) {
            wood += trees[i]-mid;
        }
    }

    return wood >= m;
}

long long int getMaxSawHeight(vector<long long int> &trees, long long int n, long long int m) {
    long long int s = 0, e = *max_element(trees.begin(), trees.end());
    long long int ans = -1;

    while(s <= e) {
        long long int mid = s+(e-s)/2;

        if(isPossible(trees, n, m, mid)) {
            ans = mid;
            s = mid+1;
        } else {
            e = mid-1;
        }
    }

    return ans;
}

int main() {
    long long int n,m;
    cin >> n >> m;
    vector<long long int> trees;
    
    for(int i=0; i<n; i++) {
        long long int h;
        cin >> h;
        trees.push_back(h);
    }

    cout << getMaxSawHeight(trees, n, m);
}