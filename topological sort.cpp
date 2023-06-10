#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> indegree(v,0);
    vector<int> adj[v];
    for (auto val: edges){
        indegree[val[1]]++;
        adj[val[0]].push_back(val[1]);
    }
    queue<int> q;
    for (int i=0; i<v; i++){
        if (indegree[i]==0)q.push(i);
    }
    vector<int> topo;
    while (!q.empty()){
        int node= q.front();
        topo.push_back(node);
        q.pop();
        for (auto adjNode: adj[node]){
            indegree[adjNode]--;
            if (indegree[adjNode]==0)q.push(adjNode);
        }
    }
    return topo;
}
