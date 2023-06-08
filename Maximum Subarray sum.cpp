// https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long ans=0; long long curr=0;
    for (int i=0; i<n; i++){
        curr+= arr[i];
        ans= max(ans,curr);
        curr= max(curr,(long long)0);
    }
    return ans;
}
