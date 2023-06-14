#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void dfs(TreeNode<int>* root, int& k, int& ans){
    if (root==NULL)return;
    if (k==0)return;
    dfs(root->left,k,ans);
    if (k-1 == 0)ans= root->data;
    k--;
    dfs(root->right,k,ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans= -1;
    dfs(root,k,ans);
    return ans;
}
