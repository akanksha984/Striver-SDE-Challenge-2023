#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if (m>n)return ninjaAndLadoos(row2, row1, n, m, k);
    int i=max(0,k-n); int j=min(k,m);
    //if (k>m)i=1;
    //if (k<m)j= k;
    while (i<=j){
        int cut1= i+(j-i)/2;
        int cut2= k-cut1;
        int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
        if (cut1-1>=0)l1= row1[cut1-1];
        if (cut2-1>=0)l2= row2[cut2-1];
        if (cut1<m)r1= row1[cut1];
        if (cut2<n)r2= row2[cut2];

        if (l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if (l1>r2){
            j= cut1-1;
        }
        else{
            i= cut1+1;
        }
    }
    return -1;
}
