#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<int> dis(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({0,source});
    dis[source]= 0;
    vector<pair<int,int>> adj[vertices];
    for (int i=0; i<vec.size(); i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    while (!pq.empty()){
        int u= pq.top().second;
        int d= pq.top().first;
        pq.pop();
        for (auto v: adj[u]){
            if (d+v.second < dis[v.first]){
                dis[v.first]= d+v.second;
                pq.push({dis[v.first],v.first});
            }
        }
    }
    return dis;

}
