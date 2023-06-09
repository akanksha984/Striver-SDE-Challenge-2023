// https://www.codingninjas.com/codestudio/problems/dfs-traversal_8230690?challengeSlug=striver-sde-challenge&leftPanelTab=1

void dfs(int i, vector<int> adj[], vector<int>& vis, vector<int>& ans){
    ans.push_back(i);
    vis[i]=1;
    for (auto node: adj[i]){
        if (!vis[node])dfs(node,adj,vis,ans);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for (auto val: edges){
        adj[val[0]].push_back(val[1]);
        adj[val[1]].push_back(val[0]);
    }
    vector<int> vis(V,0);
    vector<vector<int>> ans;
    for (int i=0; i<V; i++){
        if (!vis[i]){
            vector<int> curr_ans;
            dfs(i,adj,vis,curr_ans);
            ans.push_back(curr_ans);
        }
    }
    return ans;
}
