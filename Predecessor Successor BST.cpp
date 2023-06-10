#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void dfs(BinaryTreeNode<int>* root, int key, pair<int,int>& ans){
    if (root==NULL)return;
    if (root->data == key){
        dfs(root->left,key,ans);
        dfs(root->right,key,ans);
    }
    else if (root->data > key){
        ans.second= root->data;
        dfs(root->left,key,ans);
    }
    else if (root->data < key){
        ans.first= root->data;
        dfs(root->right,key,ans);
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int> ans= {-1,-1};
    dfs(root,key,ans);
    return ans;
}
