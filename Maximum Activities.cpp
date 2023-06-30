#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;
    int n= start.size();
    int cnt=0;
    for (int i=0; i<n; i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int reff= 0;
    for (int i=0; i<n; i++){
        if (reff<= v[i].second){
            cnt++;
            reff= v[i].first;
        }
    }
    return cnt;
}
