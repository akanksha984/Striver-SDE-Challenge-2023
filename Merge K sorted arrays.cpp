#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=0; i<k; i++){
        for (auto el: kArrays[i]){
            pq.push(el);
        }
    }
    vector<int> ans;
    while (!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
