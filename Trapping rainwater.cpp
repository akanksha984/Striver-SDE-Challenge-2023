#include <bits/stdc++.h> 
long getTrappedWater(long *a, int n){
    // Write your code here.
    long l=0; long r= n-1;
    long ans=0;
    long lmax=0, rmax=0;
    while (l<=r){
        if (a[l]<=a[r]){
            if (a[l]>=lmax)lmax= a[l];
            else{
                ans+= lmax-a[l];
            }
            l++;
        }
        else{
            if (a[r]>=rmax)rmax= a[r];
            else{
                ans+= rmax-a[r];
            }
            r--;
        }
    }
    return ans;
}
