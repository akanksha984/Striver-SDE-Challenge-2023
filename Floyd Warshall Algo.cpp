int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> cost(n+1,vector<int>(n+1,1000000000));
    for (int i=0; i<=n; i++)cost[i][i]=0;
    for (auto val: edges){
        cost[val[0]][val[1]]= val[2];
    }
    // floyd warshall algo
    for (int via=0; via<=n; via++){
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++){
                if (cost[i][via]==1000000000 || cost[via][j]==1000000000)continue;
                cost[i][j]= min(cost[i][j],cost[i][via]+cost[via][j]);
            }
        }
    }

    return cost[src][dest];

}
