#include <bits/stdc++.h>
bool check(string& s, int i, int j){
    while (i<j){
        if (s[i]!=s[j])return false;
        i++; j--;
    }
    return true;
} 
void helper(string& s, int i, vector<string>& path, vector<vector<string>>& ans){
    if (i==s.size()){
        ans.push_back(path);
        return;
    }
    for (int j=i; j<s.size(); j++){
        if (check(s,i,j)){
            path.push_back(s.substr(i,j-i+1));
            helper(s,j+1,path,ans);
            path.pop_back();
        }
    }

}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> curr;
    helper(s,0,curr,ans);
    return ans;
}
