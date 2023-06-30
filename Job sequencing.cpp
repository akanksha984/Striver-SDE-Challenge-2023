#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    vector<pair<int,int>> v;
    int profit=0;
    int n=jobs.size();
    for (int i=0; i<n; i++){
        v.push_back({jobs[i][1],jobs[i][0]});   // profit deadline
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<int> temp(n,0);
    for (int i=0; i<n; i++){
        for (int j= min(n-1,v[i].second-1); j>=0; j--){
            if (temp[j]==0){
                temp[j]=1;
                profit+= v[i].first;
                break;
            }
        }
    }
    return profit;
}
