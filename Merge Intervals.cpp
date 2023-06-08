// https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i=1; i<intervals.size(); i++){
        if (merged.back()[1] >= intervals[i][0]){
            merged.back()[1] = max(merged.back()[1],intervals[i][1]);
        }
        else{
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

