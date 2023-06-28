bool canfill(int row, int col,vector<vector<int>>& path,int n){
    for (int i=0; i<row; i++){
        if (path[i][col]==1)return false;
    }
    for (int i= row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if (path[i][j]==1)return false;
    }
    for (int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
        if (path[i][j]==1)return false;
    }
    return true;
}
void helper(int i, int n, vector<vector<int>>& path, vector<vector<int>>& ans){
    if (i==n){
        vector<int> row;
        for (auto val: path){
            for (auto x: val)row.push_back(x);
        }
        ans.push_back(row);
        return;
    }
    for (int j=0; j<n; j++){
        if (canfill(i,j,path,n)){
            path[i][j]=1;
            helper(i+1,n,path,ans);
            path[i][j]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> path(n,vector<int>(n,0));
    helper(0,n,path,ans);
    return ans;
}

/* 
bool canfill(int row, int col,vector<int>& path,int n){
    int curr= (row*n)+col;
    for (int i=0; i<row; i++){
        int n1= ((i*n)+col);
            if (path[n1]==1)return false;
    }
    for (int j=0; j<col; j++){
        int n1= ((row*n)+j);
            if (path[n1]==1)return false;
    }
    int diff= (n+1);
    for (int i= curr-diff; i>=0; i-=diff){
        if (path[i]==1)return false;
    }
    int diff2= (n-1);
    for (int i= curr-diff2; i>=0; i-=diff2){
        if (path[i]==1)return false;
    }
    return true;
}
void helper(int i, int n, vector<int>& path, vector<vector<int>>& ans){
    if (i==n){
        ans.push_back(path);
        return;
    }
    for (int j=0; j<n; j++){
        if (canfill(i,j,path,n)){
            path[(n*i)+j]=1;
            helper(i+1,n,path,ans);
            path[(n*i)+j]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> path(n*n,0);
    helper(0,n,path,ans);
    return ans;
} */
