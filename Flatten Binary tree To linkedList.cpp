#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
void flatten(TreeNode<int>* root, TreeNode<int>* &next){
    if (root==NULL)return;
    flatten(root->right,next);
    flatten(root->left,next);
    root->left= NULL;
    root->right= next;
    next= root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>* next= NULL;
    flatten(root,next);
    return root;
}
