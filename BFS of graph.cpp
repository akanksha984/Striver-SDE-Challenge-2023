#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    set<int> adj[vertex];
    for (auto val: edges){
        adj[val.first].insert(val.second);
        adj[val.second].insert(val.first);
    }
    vector<int> vis(vertex,0);
    for (int i=0; i<vertex; i++){
        if (!vis[i]){
            //bfs
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while (!q.empty()){
                int curr= q.front();
                q.pop();
                ans.push_back(curr);
                for (auto node: adj[curr]){
                    if (!vis[node]){
                        q.push(node);
                        vis[node]=1;
                    }
                }
            }
        }
    }
    return ans;

}
