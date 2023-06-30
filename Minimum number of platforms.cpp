int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int ans=0;
    int curr=0;
    int i=0, j=0;
    while (i<n){
        if (at[i]<=dt[j]){
            curr++;
            ans= max(ans,curr);
            i++;
        }
        else{
            j++;
            curr--;
        }
    }
    return ans;
}
