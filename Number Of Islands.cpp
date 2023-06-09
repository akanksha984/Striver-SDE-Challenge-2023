// https://www.codingninjas.com/codestudio/problems/find-number-of-islands_8230692?challengeSlug=striver-sde-challenge&leftPanelTab=1

 void dfs(int i, int j, int** arr,vector<vector<int>>& vis, int n, int m){
   vis[i][j]=1;
   int dx[]= {-1,-1,-1,0,0,1,1,1};
   int dy[]= {1,0,-1,1,-1,1,-1,0};
   for (int it=0; it<8; it++){
      int nr= i+dx[it];
      int nc= j+dy[it];
      if (nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && arr[nr][nc]==1){
         dfs(nr,nc,arr,vis,n,m);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ans=0;
   vector<vector<int>> vis(n,vector<int>(m,0));
   for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
         if (!vis[i][j] && arr[i][j]==1){
            ans++;
            dfs(i,j,arr,vis,n,m);
         }
      }
   }
   return ans;
}
