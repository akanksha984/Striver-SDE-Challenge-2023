#include<bits/stdc++.h>
void helper(int i,string s,string curr,unordered_set<string> st,vector<string>& res){
        if(i==s.length()){
            curr.pop_back();
            res.push_back(curr);
        }
        string str="";
        for(int j=i;j<s.length();j++){
            str.push_back(s[j]);
            if(st.count(str)){
                helper(j+1,s,curr+str+" ",st,res);
            }
        }
    }
vector<string> wordBreak(string &s, vector<string> &dictionary){
    // Write your code here
    unordered_set<string> st;
        vector<string> res;
    for(auto word:dictionary)
            st.insert(word);
    string curr="";
        helper(0,s,curr,st,res);
        return res;

}
