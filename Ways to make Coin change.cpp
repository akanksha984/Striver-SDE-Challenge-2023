#include <bits/stdc++.h>
long helper(int i, int sum, int* denominations, vector<vector<long>>& dp){
    if (i==0){
        if (sum%denominations[i]==0)return 1;
        return 0;
    }
    long pick= 0;
    if (denominations[i]<= sum){
        pick= helper(i,sum-denominations[i],denominations,dp);
    }
    long notPick= helper(i-1,sum,denominations,dp);
    return (pick+notPick);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //vector<vector<long>> dp(n,vector<long>(value+1,-1));
    //return helper(n-1,value,denominations,dp);

    // tabulation
    /* vector<vector<long>> dp(n,vector<long>(value+1,0));
    for (int j=0; j<=value; j++){
        dp[0][j]= (value%denominations[0]==0);
    }
    
    for (int i=1; i<n; i++){
        for (int sum=0; sum<=value; sum++){
            long pick= 0;
            if (denominations[i]<=sum)pick= dp[i][sum-denominations[i]];
            long notPick= dp[i-1][sum];
            dp[i][sum]= pick+notPick;
        }
    }
    return dp[n-1][value];
     */

    // Space optimization
    vector<long>prev (value+1,0);
    for (int j=0; j<=value; j++){
        prev[j]= (value%denominations[0]==0);
    }
    
    for (int i=1; i<n; i++){
        vector<long> curr(value+1,0);
        for (int sum=0; sum<=value; sum++){
            long pick= 0;
            if (denominations[i]<=sum)pick= curr[sum-denominations[i]];
            long notPick= prev[sum];
            curr[sum]= pick+notPick;
        }
        prev= curr;
    }

    return prev[value];
}
