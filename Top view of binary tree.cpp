#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if (root==NULL)
      return {};
    vector<int> ans;
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while (!q.empty()){
        TreeNode<int>* node= q.front().first;
        int ind= q.front().second;
        q.pop();
        if (mp.find(ind)==mp.end())mp[ind]= node->val;
        if (node->left)q.push({node->left,ind-1});
        if (node->right)q.push({node->right,ind+1});
    }
    for (auto vl: mp)ans.push_back(vl.second);
    return ans;
}
