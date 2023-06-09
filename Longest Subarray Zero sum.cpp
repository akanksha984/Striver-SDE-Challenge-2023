// https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_8230747?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int st=0; int len=0; int sm=0;
  unordered_map<int,int> mp;
  mp[0]=-1;
  for (int i=0; i<arr.size(); i++){
    sm+= arr[i];
    if (mp.find(sm)!=mp.end()){
      len= max(len,i-mp[sm]);
    }
    else mp[sm]=i;
  }
  return len;
}
