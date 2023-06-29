#include <bits/stdc++.h> 
void helper(int i, int j, vector<vector<int>>& maze, int n, vector<vector<int>>& vis, vector<vector<int>>& ans){
  if (maze[i][j]==0)return;
  if (i==n-1 && j==n-1){
    vis[i][j]=1;
    vector<int> val;
    for (auto row: vis){
      for (auto el: row){
        val.push_back(el);
      }
    }
    ans.push_back(val);
    return;
  }
  int dx[]= {-1,1,0,0};
  int dy[]= {0,0,-1,1};
  vis[i][j]=1;
  for (int it=0; it<4; it++){
    int x= i+dx[it];
    int y= j+dy[it];
    if (x>=0 && y>=0 && x<n && y<n && maze[x][y]==1 && vis[x][y]==0){
      vis[x][y]=1;
      helper(x,y,maze,n,vis,ans);
      vis[x][y]=0;
    }
  }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  vector<vector<int>> vis(n,vector<int>(n,0));
  helper(0,0,maze,n,vis,ans);
  return ans;
}
