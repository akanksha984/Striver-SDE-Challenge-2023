#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    vector<int> ans= permutation;
    int ind1=-1, ind2=0;
    for (int i=n-1; i>0; i--){
        if (permutation[i-1]<permutation[i]){
            ind1= i-1;
            break;
        }
    }
    if (ind1!= -1){
        for (int i=n-1; i>=0; i--){
            if (permutation[i]>permutation[ind1]){
                ind2= i;
                break;
            }
        }
        swap(ans[ind1],ans[ind2]);    
    }
    
    int low= ind1+1, high= n-1;
    while (low<high)swap(ans[low++],ans[high--]);
    return ans;
}
