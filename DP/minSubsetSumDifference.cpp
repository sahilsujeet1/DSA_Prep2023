#include <bits/stdc++.h>
using namespace std;

int getMinDiffRec(vector<int>& arr, int i, int sum, int totalSum) {
	if(i == 0) {
		return abs((totalSum- sum) - sum);
	}

	int include = getMinDiffRec(arr, i-1, sum+arr[i], totalSum);
	int exclude = getMinDiffRec(arr, i-1, sum, totalSum);
	int ans = min(include, exclude);

	return ans;
}

int getMinDiffMem(vector<int>& arr, int i, int sum, int totalSum, vector<vector<int>>& dp) {
	if(i == 0) {
		return abs((totalSum- sum) - sum);
	}

	if(dp[i][sum] != -1) return dp[i][sum];

	int include = getMinDiffMem(arr, i-1, sum+arr[i], totalSum, dp);
	int exclude = getMinDiffMem(arr, i-1, sum, totalSum, dp);
	dp[i][sum] = min(include, exclude);

	return dp[i][sum];
}

int getMinDiffTab(vector<int>& arr, int totalSum) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(totalSum+1, 0));
	
	for(int i=0; i<=totalSum; i++) {
		dp[0][i] = abs((totalSum - i) - i);
	}

	for(int i=1; i<n; i++) {
		for(int s=0; s<=totalSum; s++) {
			int include = dp[i-1][s+arr[i]];
			int exclude = dp[i-1][s];
			dp[i][s] = min(include, exclude);
		}
	}

	return dp[n-1][0];
}

int getMinDiffTabSO(vector<int>& arr, int totalSum) {
	int n = arr.size();

	vector<int> prev(totalSum+1, 0);
	vector<int> curr(totalSum+1, 0);

	for(int i=0; i<=totalSum; i++) {
		prev[i] = abs((totalSum - i) - i);
	}
	
	for(int i=1; i<n; i++) {
		for(int s=0; s<=totalSum; s++) {
			int include = prev[s+arr[i]];
			int exclude = prev[s];
			curr[s] = min(include, exclude);
		}
		prev = curr;
	}

	return prev[0];
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;
	for(int i:arr) sum += i;

	// vector<vector<int>> dp(n, vector<int>(sum+1, -1));

	// return getMinDiff(arr, n-1, 0, sum);
	// return getMinDiffMem(arr, n-1, 0, sum, dp);
	// return getMinDiffTab(arr, sum);
	return getMinDiffTabSO(arr, sum);

}

int main() {
    vector<int> num{9,67,15,64};
    cout << minSubsetSumDifference(num, num.size());
}