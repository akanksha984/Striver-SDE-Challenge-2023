int greaterEqual(vector<vector<int>>& matrix, int el){
    int cnt=0;
    for (int ind=0; ind<matrix.size(); ind++){
        int i=0; int j= matrix[0].size()-1;
        while (i<=j){
            int mid= i+(j-i)/2;
            if(matrix[ind][mid]<= el){
                i= mid+1;
            }
            else{
                j= mid-1;
            }
        }
        cnt+=i;
    }
    return cnt;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int req= (matrix.size()*matrix[0].size())/2;
    int i=0, j= 1e5;
    while (i<=j){
        int mid= i+(j-i)/2;
        if (greaterEqual(matrix,mid)<=req){
            i= mid+1;
        }
        else{
            j= mid-1;
        }
    }
    return i;
}
