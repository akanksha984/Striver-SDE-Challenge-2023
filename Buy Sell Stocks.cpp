#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int ans=0; int mini=prices[0];
    for (int i=1; i<prices.size(); i++){
        ans= max(prices[i]-mini,ans);
        mini= min(prices[i],mini);
    }
    return ans;
}
