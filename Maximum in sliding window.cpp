#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> dq;
    for (int i=0; i<k; i++){
        if (dq.empty()){
            dq.push_back(i);
        }
        else{
            while (!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    vector<int> ans;
    ans.push_back(nums[dq.front()]);
    for (int i=k; i<nums.size(); i++){
        if (dq.front()== (i-k))dq.pop_front();
        while (!dq.empty() && nums[i] > nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}
