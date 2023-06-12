int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int j=0;
    int zer=0, one=0;
    int ans=0;
    for (int i=0; i<n; i++){
        if (arr[i]==1)one++;
        else{
            zer++;
            while(zer>k){
                if (arr[j]==1)one--;
                else zer--;
                j++;
            }
        }
        ans= max(ans,i-j+1);
    }
    return ans;
}
