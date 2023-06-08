// https://www.codingninjas.com/codestudio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    int n= arr.size();
    int req= n/3;
    map<int,int> mp;
    for (int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    for (auto vl: mp){
        if (vl.second > req)ans.push_back(vl.first);
    }
    return ans;

}
