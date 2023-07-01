#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for (int i=0; i<n; i++){
        if (i>0 && arr[i-1]==arr[i]){
            continue;
        }
        for (int j=i+1; j<n; j++){
            if (j>i+1 && arr[j-1]==arr[j]){
                continue;
            }
            int low= j+1, high= n-1;
            int req= target-(arr[i]+arr[j]);
            while (low<=high){
                if (arr[low]+arr[high]==req){
                    return "Yes";
                }
                if (arr[low]+arr[high]>req){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
    }
    return "No";
}
