#include <bits/stdc++.h>
using namespace std;

int getMaxRec(vector<int> w, vector<int> v, int n, int capacity) {
	if(n == 0) {
		if(w[0] <= capacity) {
			return v[0];
		} else
			return 0;
	}

	int include = 0;
	if(w[n] <= capacity)
		include = v[n] + getMaxRec(w, v, n-1, capacity-w[n]);
	int exclude = 0 + getMaxRec(w, v, n-1, capacity);

	int ans = max(include, exclude);
	return ans;
}

int getMaxMem(vector<int> w, vector<int> v, int n, int capacity, vector<vector<int>>& dp) {
	if(n == 0) {
		if(w[0] <= capacity) {
			return v[0];
		} else
			return 0;
	}

	if(dp[n][capacity] != -1) return dp[n][capacity];

	int include = 0;
	if(w[n] <= capacity)
		include = v[n] + getMaxMem(w, v, n-1, capacity-w[n], dp);
	int exclude = 0 + getMaxMem(w, v, n-1, capacity, dp);

	dp[n][capacity] = max(include, exclude);
	return dp[n][capacity];
}

int getMaxTab(vector<int> w, vector<int> v, int n, int capacity) {
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	for(int i=w[0]; i<=capacity; i++) {
		if(w[0] <= capacity) {
			dp[0][i] = v[0];
		} else {
			dp[0][i] = 0;
		}
	}

	for(int i=1; i<n; i++) {
		for(int c=0; c<=capacity; c++) {
			int include = 0;
			if(w[i] <= c)
				include = v[i] + dp[i-1][c-w[i]];
			int exclude = 0 + dp[i-1][c];

			dp[i][c] = max(include, exclude);
		}
	}

	return dp[n-1][capacity];
}

int getMaxTabSO(vector<int> w, vector<int> v, int n, int capacity) {
	// vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for(int i=w[0]; i<=capacity; i++) {
		if(w[0] <= capacity) {
			prev[i] = v[0];
		} else {
			prev[i] = 0;
		}
	}

	for(int i=1; i<n; i++) {
		for(int c=0; c<=capacity; c++) {
			int include = 0;
			if(w[i] <= c)
				include = v[i] + prev[c-w[i]];
			int exclude = 0 + prev[c];

			curr[c] = max(include, exclude);
            // prev = curr; yhi pe glti hogi
		}
		prev = curr;
	}

	return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return getMaxRec(weight, value, n-1, maxWeight);
	// return getMaxMem(weight, value, n-1, maxWeight, dp);
	// return getMaxTab(weight, value, n, maxWeight);
	return getMaxTabSO(weight, value, n, maxWeight);
}