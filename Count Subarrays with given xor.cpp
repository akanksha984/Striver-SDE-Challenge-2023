#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int cnt=0;
    unordered_map<int,int> hash;
    int pref=0;
    for (int i=0; i<arr.size(); i++){
        pref^= arr[i];
        if (pref==x)cnt++;
        int other= pref^x;
        if (hash.find(other)!= hash.end()){
            cnt+= hash[other];
        }
        hash[pref]++;
    }
    return cnt;
}
