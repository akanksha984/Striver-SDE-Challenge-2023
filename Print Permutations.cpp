#include <bits/stdc++.h> 

void helper(string& ds, string s, vector<int>& vis, vector<string>& ans){
    if (ds.size()== s.size()){
        ans.push_back(ds);
        return;
    }
    for (int j=0; j<s.size(); j++){
        if (!vis[j]){ 
            vis[j]=1;  
            ds+= s[j];
            helper(ds,s,vis,ans);
            ds.pop_back();
            vis[j]=0;
        }
    }
}

void helper2(int i, string s, vector<string>& ans){
    if (i==s.size()){
        ans.push_back(s);
        return;
    }
    for (int j=i; j<s.size(); j++){
        //helper2(i+1,s,ans);
        swap(s[j],s[i]);
        helper2(i+1,s,ans);
        //swap(s[j],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    //string ds="";
    //vector<int> vis(s.size(),0);
    //helper(ds,s,vis,ans);
    helper2(0,s,ans);
    return ans;
}
