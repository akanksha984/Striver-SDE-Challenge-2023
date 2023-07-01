#include <bits/stdc++.h> 
bool check(vector<int> &positions,int gap,int n,int c){
    c--;
    int curr = 0;
    for(int i = 1;i<n;i++){
        if(positions[i]-positions[curr]>=gap){
            c--;
            curr = i;
        }
        if(c==0)return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
    int l = 1;
    int r = positions[n-1];
    int ans;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(positions,mid,n,c)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
