#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> ranks, int nC, int nP, int mid) {
    int p = 0;

    for(int i=0; i<nC; i++) {
        int rank = ranks[i], j=1;
        int time = 0;

        while(true) {
            if(time + j*rank <= mid) {
                p++;
                time += rank * j;
                j++;
            } else {
                break;
            }
        }

        if(p >= nP) return true;
    }
    return false;
}

int maxTimeTaken(int nP, int nC, vector<int> ranks) {
    int s = 0, highestRank = *max_element(ranks.begin(), ranks.end());;
    int ans = -1, e = highestRank * (nP * (nP+1)/2);

    while(s <= e) {
        int mid = s+(e-s)/2;

        if(isPossible(ranks, nC, nP, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int nP, nC;
        cin >> nP >> nC;
        vector<int> ranks;
        for(int i=0; i<nC; i++) {
            int R;
            cin >> R;
            ranks.push_back(R);
        }

        cout << maxTimeTaken(nP, nC, ranks) << endl;
    }
}