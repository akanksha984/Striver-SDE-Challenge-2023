#include <bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> vis(n+1,0);
    vector<int> adj[n+1];
    for (auto vl: edges){
        adj[vl[0]].push_back(vl[1]);
        adj[vl[1]].push_back(vl[0]);
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            //bfs
            queue<pair<int,int>> q;
            q.push({i,-1});
            vis[i]=1;
            while (!q.empty()){
                int node= q.front().first;
                int par= q.front().second;
                q.pop();
                for (auto child: adj[node]){
                    if (!vis[child]){
                        q.push({child,node});
                        vis[child]= 1;
                    }
                    else{
                        if (child!=par)return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}
