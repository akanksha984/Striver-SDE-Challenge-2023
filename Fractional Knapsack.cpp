#include <bits/stdc++.h> 
bool comp(pair<int,int>& a, pair<int,int>& b){
    double ratioA= (double)a.second/(double)a.first;
    double ratioB= (double)b.second/(double)b.first;
    return ratioA>ratioB;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double ans=0; int curr_weight=0;
    for (int i=0; i<n; i++){
        if (curr_weight == w)break;
        if ((curr_weight+items[i].first)<=w){
            ans+= items[i].second;
            curr_weight+= items[i].first;
        }
        else{
            ans+= (double)(w-curr_weight)*((double)items[i].second/(double)items[i].first);
            break;
        }
    }
    return ans;
}
