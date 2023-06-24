#include <bits/stdc++.h> 
void helper(int i, vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans){
    ans.push_back(ds);
    if (i==arr.size()){
        return;
    }
    for (int j=i; j<arr.size(); j++){
        if (j!=i && arr[j]==arr[j-1])continue;
        ds.push_back(arr[j]);
        helper(j+1,ds,arr,ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    helper(0,ds,arr,ans);
    return ans;
}
