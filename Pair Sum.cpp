

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   unordered_map<int,int> mp;
   //int i=0; int j= arr.size()-1;
   for (int i=0; i<arr.size(); i++){
      int req= s-arr[i];
      if (mp.find(req)!=mp.end()){
         for(int x=0; x<mp[req]; x++)
         ans.push_back({min(arr[i],req),max(arr[i],req)});
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}


#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   /* vector<vector<int>> ans;
   unordered_map<int,int> mp;
   //int i=0; int j= arr.size()-1;
   for (int i=0; i<arr.size(); i++){
      int req= s-arr[i];
      if (mp.find(req)!=mp.end()){
         for(int x=0; x<mp[req]; x++)
         ans.push_back({min(arr[i],req),max(arr[i],req)});
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans; */

   vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   int n= arr.size();
   int i=0; int j= n-1;
   while (i<n){
      if (arr[i]+arr[j] == s){
         ans.push_back({arr[i],arr[j]});
      }
      j--;
      if (j<=i){
         i++; j= n-1;
      }
   }
   return ans;
}
