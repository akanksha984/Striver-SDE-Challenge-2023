#include <bits/stdc++.h>
void dfs(int i, vector<int>& vis, vector<int> adj[], stack<int>& stk){
    vis[i]= 1;
    for (auto child : adj[i]){
        if (!vis[child])dfs(child,vis,adj,stk);
    }
    stk.push(i);
}
void dfs2(int i, vector<int>& vis, vector<int> adjrev[], vector<int>& temp){
    temp.push_back(i);
    vis[i]=1;
    for (auto child: adjrev[i]){
        if (!vis[child]){
            dfs2(child, vis, adjrev,temp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n], adjrev[n];
    for (int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adjrev[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n,0);
    stack<int> stk;
    for (int i=0; i<n; i++){
        if (!vis[i])dfs(i,vis,adj,stk);
    }
    vector<vector<int>> ans;
    for (int i=0; i<n; i++)vis[i]=0;
    while (!stk.empty()){
        int el= stk.top();
        stk.pop();
        if (!vis[el]){
            vector<int> temp;
            dfs2(el,vis,adjrev,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
