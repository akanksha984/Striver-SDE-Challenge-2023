#include <bits/stdc++.h> 
bool check(string s, int i, int j){
    while (i<j){
        if (s[i++]!=s[j--])return false;
    }
    return true;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n= str.size();
    vector<int> dp(n+1,0);
    for (int i= n-1; i>=0; i--){
        int mn= 1e9;
        for (int j=i; j<n; j++){
            if (check(str,i,j)){
                mn= min(mn,1+dp[j+1]);
            }
        }
        dp[i]= mn;
    }
    return dp[0]-1;
}
