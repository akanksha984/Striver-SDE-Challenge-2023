#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> nse(n,-1);
    stack<int> stk;
    for (int i=n-1; i>=0; i--){
        if(stk.empty()){
            stk.push(arr[i]);
        }
        else{
            if (stk.top()<arr[i]){
                nse[i]= stk.top();
                stk.push(arr[i]);
            }
            else{
                while (!stk.empty() && arr[i]<= stk.top()){
                    stk.pop();
                }
                if (!stk.empty())nse[i]= stk.top();
                stk.push(arr[i]);
            }
        }
    }
    return nse;
}
