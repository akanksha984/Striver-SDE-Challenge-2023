#include <bits/stdc++.h> 
int atoi(string s) {
    // Write your code here.
    int ans=0;
    for (int i=0; i<s.size(); i++){
        if (s[i]>='0' && s[i]<='9'){
            ans*=10;
            ans+= (s[i]-'0');
        }
    }
    if (s[0]=='-'){
        ans*=-1;
    }
    return ans;
}
