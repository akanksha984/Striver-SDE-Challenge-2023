bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n= mat.size(); int m= mat[0].size();
    int i=0; int j= n*m-1;
    while (i<=j){
        int mid= i+(j-i)/2;
        int curr= mat[mid/m][mid%m];
        if (curr==target)return true;
        if (curr>target){
            j= mid-1;
        }
        else{
            i= mid+1;
        }
    }
    return false;
}
