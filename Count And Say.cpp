#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) {
   string ans = "1";
   if(n==1)
       return ans;
   for(int i = 0 ;i<n-1;i++){
       int cnt=1;string temp;
       for(int j=0;j<ans.size();j++){
           if(ans[j]==ans[j+1])
               cnt++;
           else{
               temp+=to_string(cnt);
               temp+=ans[j];
               cnt=1;
           }
       }
       ans=temp;
   }
   return ans;
}
