#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> nge(n,-1);
    stack<int> stk;
    for (int i=n-1; i>=0; i--){
        if (!stk.empty()){
            if (stk.top()> arr[i]){
                nge[i]= stk.top();
                stk.push(arr[i]);
            }
            else{
                while (!stk.empty() && stk.top()<=arr[i]){
                    stk.pop();
                }
                if (!stk.empty())nge[i]= stk.top();
                stk.push(arr[i]);
            }
        }
        else{
            stk.push(arr[i]);
        }
    }
    return nge;

}
