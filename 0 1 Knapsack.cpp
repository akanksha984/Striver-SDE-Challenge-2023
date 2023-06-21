int helper(int i, int cap, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
	if (i==0){
		if (wt[i]<=cap)return val[i];
		return 0;
	}
	if (dp[i][cap]!= -1)return dp[i][cap];
	int notPick= helper(i-1,cap,wt,val,dp);
	int pick=0;
	if (wt[i]<=cap)pick= val[i]+ helper(i-1,cap-wt[i],wt,val,dp);
	return dp[i][cap]= max(pick,notPick);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return helper(n-1,w,weights,values,dp);
}
