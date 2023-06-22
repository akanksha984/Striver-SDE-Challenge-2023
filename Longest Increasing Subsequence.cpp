#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    /* vector<int> dp(n,1);
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[j]<arr[i]){
                dp[i]= max(dp[i],1+dp[j]);
            }
        }
    }
    int ans= 1;
    for (int i=0; i<n; i++){
        ans= max(ans,dp[i]);
    }
    return ans; */

    
    vector<int> curr;
    for (int i=0; i<n; i++){
        int lb= lower_bound(curr.begin(),curr.end(),arr[i])-curr.begin();
        if (lb== curr.size()){
            curr.push_back(arr[i]);
        }
        else{
            curr[lb]= arr[i];
        }
    }
    return curr.size();
}
