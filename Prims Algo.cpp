#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for (auto val: g){
      adj[val.first.first].push_back({val.first.second,val.second});
      adj[val.first.second].push_back({val.first.first,val.second});
    }
    vector<pair<pair<int,int>,int>> mst;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>> >pq; // wt node par
    pq.push({0,1,-1});
    vector<int> vis(n+1,0);
    while (!pq.empty()){
        int wt= pq.top()[0];
        int node= pq.top()[1];
        int par= pq.top()[2];
        pq.pop();
        if (vis[node])continue;
        vis[node]=1;
        if (par!= -1){
            mst.push_back({{node,par},wt});
        }
        for (auto val: adj[node]){
            if (!vis[val.first]){
                pq.push({val.second,val.first,node});
            }
        }
    }
    
    return mst;
}
