#include<stack>
vector<int> findSpans(vector<int> &price) {
   // Write your code here.
   stack<pair<int,int>> st;
   vector<int> result;
   int n=price.size();
   for(int i=0;i<n;i++){
         int res=1;
       while(!st.empty() && st.top().first<=price[i]){
           res+=st.top().second;
           st.pop();
       }
       st.push({price[i],res});
      result.push_back(res);
   }
   return result;
}
