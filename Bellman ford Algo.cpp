#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dis(n+1,1000000000);
    dis[src]=0;
    for (int i=0; i<n-1; i++){
        for (auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            int wt= edge[2];
            if (dis[u]== 1000000000)continue;
            else{
                if (dis[u]+wt < dis[v]){
                    dis[v]= dis[u]+wt;
                }
            }
        }
    }
    return dis[dest];
}
