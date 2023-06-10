void dfs(int x, int y, int old, vector<vector<int>>& ans, int color){
    ans[x][y]= color;
    int dx[]= {-1,1,0,0};
    int dy[]= {0,0,1,-1};
    for (int it=0; it<4; it++){
        int nr= x+dx[it];
        int nc= y+dy[it];
        if (nr>=0 && nr<ans.size() && nc>=0 && nc<ans[0].size() && ans[nr][nc]==old){
            dfs(nr,nc,old,ans,color);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> ans= image;
    if (image[x][y]==newColor)return ans;
    dfs(x,y,image[x][y],ans,newColor);
    return ans;
}
