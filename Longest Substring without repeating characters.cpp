#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int> mp;
    int ans=1; //int curr=1;
    int i=0;
    for (int j=0; j<input.size(); j++){
        mp[input[j]]++;
        if (mp.find(input[j])==mp.end()){
            //curr++;
        }
        else{
            while (mp[input[j]]!=1){
                mp[input[i++]]--;
            }
            //curr=1
        }
        ans= max(ans,j-i+1);
    }
    return ans;
}
