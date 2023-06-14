#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool check(BinaryTreeNode<int>* root, int mini, int maxi){
    if (root==NULL)return true;
    if (root->data >maxi || root->data <mini)return false;
    return check(root->left,mini,root->data) && check(root->right,root->data,maxi);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int mini= INT_MIN;
    int maxi= INT_MAX;
    return check(root,mini,maxi);
}
