#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> mp;
    for (int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for (auto vl: mp){
        if (pq.size()<k){
            pq.push({vl.second,vl.first});
        }
        else{
            if (pq.top().first < vl.second){
                pq.pop();
                pq.push({vl.second,vl.first});
            }
            else if (pq.top().first== vl.second){
                if (pq.top().second < vl.first){
                    pq.pop();
                    pq.push({vl.second,vl.first});
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
