bool possible(int node, int c, vector<vector<int>>& mat, vector<int>& color){
    for (int i=0; i<mat.size(); i++){
        if (i==node)continue;
        if (mat[node][i]==1){
            if (color[i]==c)return false;
        }
    }
    return true;
}
bool helper(int node, vector<vector<int>>& mat, vector<int>& color, int m){
    if (node==mat.size())return true;

    for (int i=1; i<=m; i++){
        if (possible(node,i,mat,color)){
            color[node]= i;
            if (helper(node+1,mat,color,m)){
                return true;
            }
            else color[node]= 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n= mat.size();
    vector<int> color(n,0);
    if (helper(0,mat,color,m))return "YES";
    return "NO";
}
