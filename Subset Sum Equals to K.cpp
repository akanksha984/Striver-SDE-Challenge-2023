#include <bits/stdc++.h> 
bool check(int i, int sum, vector<int>& arr, vector<vector<int>>& dp){
    if (sum==0)return 1;
    if (i==0){
        if (arr[i]==sum)return 1;
        return 0;
    }
    if (dp[i][sum]!= -1)return dp[i][sum];
    bool pick= 0;
    if (arr[i]<=sum)pick= check(i-1,sum-arr[i],arr,dp);
    bool notPick= check(i-1,sum,arr,dp);
    return dp[i][sum]= pick|notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return check(n-1,k,arr,dp);
}
