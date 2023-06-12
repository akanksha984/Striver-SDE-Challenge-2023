
bool hasCycle(int i, vector<int>& vis, vector<int>& pathvis, vector<int> adj[]){
  vis[i]=1; 
  pathvis[i]=1;
  for (auto child: adj[i]){
    if (!vis[child]){
      if (hasCycle(child,vis,pathvis,adj))return true;
    }
    else if (pathvis[child]){
      return true;
    }
  }
  pathvis[i]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for (auto val: edges){
    adj[val.first].push_back(val.second);
  }
  vector<int> vis(n+1,0), pathvis(n+1,0);
  for (int i=0; i<=n; i++){
    if (!vis[i]){
      if (hasCycle(i,vis,pathvis,adj))return 1;
    }
  }
  return 0;
}
