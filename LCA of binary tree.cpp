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
TreeNode<int>* lca(TreeNode<int>* root,int x, int y){
    if(root==NULL)return NULL;
    if (root->data == x || root->data == y){
        return root;
    }
    TreeNode<int>* left_lca= lca(root->left,x,y);
    TreeNode<int>* right_lca= lca(root->right,x,y);
    if (left_lca && right_lca)return root;
    if (!left_lca)return right_lca;
    return left_lca;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int>* val= lca(root,x,y);
    if (val)return val->data;
    return -1;
}
