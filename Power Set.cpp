#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    int n= v.size();
    int tot= (1<<n);
    for (int i=0; i<tot; i++){
        vector<int> curr;
        for (int j=0; j<n; j++){
            int bit= (1<<j)&i;
            if (bit!= 0)curr.push_back(v[j]);
        }
        ans.push_back(curr);
    }
    return ans;
}
