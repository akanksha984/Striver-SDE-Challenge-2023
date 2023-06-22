#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));

	for (int i=n-1; i>=0; i--){
		for (int prev=i-1; prev>= -1; prev--){
			int notTake= dp[i+1][prev+1];
			int take= -1e9;
			if (prev==-1 || rack[i]>rack[prev]){
				take= rack[i]+ dp[i+1][i+1];
			}
			dp[i][prev+1]= max(take,notTake);
		}
	}
	return dp[0][0];
}
