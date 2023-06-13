#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void dfs(TreeNode<int>* root, int& k, int& ans){
    if (root==NULL)return;
    if (k==0)return;
    dfs(root->right,k,ans);
    k--;
    if (k==0)ans= root->data;
    dfs(root->left,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans= -1;
    dfs(root,k,ans);
    return ans;
}
