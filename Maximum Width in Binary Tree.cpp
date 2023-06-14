#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans=0;
    if (root==NULL)return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()){
        int sz= q.size();
        ans= max(ans,sz);
        while (sz--){
            TreeNode<int>* curr= q.front();
            q.pop();
            if (curr->left)q.push(curr->left);
            if (curr->right)q.push(curr->right);
        }
    }
    return ans;
}
