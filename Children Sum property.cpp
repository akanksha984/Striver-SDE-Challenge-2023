#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void dfs(BinaryTreeNode<int>* root){
    if (root==NULL)return;
    if (root->left==NULL && root->right==NULL)return;
    int child=0;
    if (root->left){
        child+= root->left->data;
    }
    if (root->right){
        child+= root->right->data;
    }
    if (child < root->data){
        if(root->left)root->left->data= root->data;
        else if(root->right)root->right->data= root->data;
    }
    dfs(root->left);
    dfs(root->right);
    //if (root->left==NULL && root->right==NULL)return;
    int tot=0;
    if (root->left){
        tot+= root->left->data;
    }
    if (root->right){
        tot+= root->right->data;
    }
    if(root->left || root->right)root->data= tot;
    return;
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if (root==NULL)return;
    if (root->left==NULL && root->right==NULL)return;
    dfs(root);
}  
