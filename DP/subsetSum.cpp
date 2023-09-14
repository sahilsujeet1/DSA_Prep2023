#include <bits/stdc++.h>
using namespace std;

// // Not yet used DP :(

void getSubsetSum(vector<int> &num, int i, int sum, vector<int>& sums) {
    if(i == num.size()) {
        sums.push_back(sum);
        return;
    }

    getSubsetSum(num, i+1, sum+num[i], sums);

    getSubsetSum(num, i+1, sum,  sums);
}

// int getSubsetSum(vector<int> arr, int i, int sum, vector<int> &ans) {
//     if(i == arr.size()) {
//         ans.push_back(sum);
//         return sum;
//     }
//     int include = getSubsetSum(arr, i+1, sum+arr[i], ans);

//     int exclude = getSubsetSum(arr, i+1, sum, ans);

// }

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
    vector<int> sums;
    getSubsetSum(num, 0, 0, sums);
    sort(sums.begin(), sums.end());
    return sums;	
	
}

int main() {
    vector<int> num{1,2,3};
    vector<int> ans = subsetSum(num);

    for(int i:ans) cout << i << ", ";
}
