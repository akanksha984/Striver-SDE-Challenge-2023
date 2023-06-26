#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<int> ans;
    int n= start.size();
    // look at the ending time;
    vector<vector<int>> v;
    for (int i=0; i<n; i++){
        v.push_back({end[i],i+1,start[i]});
    }
    sort(v.begin(),v.end());
    int curr=-1;
    for (int i=0; i<n; i++){
        if (v[i][2]>curr){  //start
            ans.push_back(v[i][1]);
            curr= v[i][0];  //end
        }
    }
    return ans;
}
