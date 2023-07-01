#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int N){
    queue<vector<int>> q;
   unordered_map<int,int> mp;
   for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
   int k=0;
   if(mp.find(levelorder[0])!=mp.end()){
       if(mp[levelorder[0]]==inorder.size()-1)
           q.push({0,mp[levelorder[0]]-1,1});
       else if(mp[levelorder[0]]==0)
           q.push({1,(int)(inorder.size()-1),1});
       else {
           q.push({0,mp[levelorder[0]]-1,1});
           q.push({mp[levelorder[0]]+1,(int)(inorder.size()-1),1});
       }
   }
   k++;
   int ans=0;
   while(!q.empty()){
       vector<int> temp=q.front();
       q.pop();
       ans=max(ans,temp[2]);
       if(mp.find(levelorder[k])!=mp.end()){
           if(temp[1]==temp[0]){
              ans=max(ans,temp[2]+1);
             
           }
          else if(mp[levelorder[k]]==temp[1])
               q.push({temp[0],mp[levelorder[k]]-1,temp[2]+1});
           else if(mp[levelorder[k]]==temp[0])
               q.push({mp[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           else {
               q.push({temp[0],mp[levelorder[k]]-1,temp[2]+1});
     q.push({mp[levelorder[k]]+1,(int)(temp[1]),temp[2]+1});
           }
       }
       k++;
   }
   return ans-1;
}
