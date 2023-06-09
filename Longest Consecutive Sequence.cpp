#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    long long int len=1, curr=1, ele= arr[0];
    for (long long int i=1; i<n; i++){
        if (arr[i]==ele){
            
        }
        else if (arr[i]-ele==1){
            curr++;
        }
        else{
            //len= max(len,curr);
            curr=1;
        }
        len= max(len,curr);
        ele= arr[i];
    }
    return len;
}
