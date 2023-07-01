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
void traversal(BinaryTreeNode<int>* root, vector<int>& inorder){
    if (root==NULL)return ;
    traversal(root->left,inorder);
    inorder.push_back(root->data);
    traversal(root->right,inorder);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<int> inorder;
    traversal(root,inorder);
    BinaryTreeNode<int>* head= new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* newHead= head;

    for (auto val: inorder){
        BinaryTreeNode<int>* curr= new BinaryTreeNode<int>(val);
        newHead->right= curr;
        curr->left= newHead;
        newHead= newHead->right;
    }
    return head->right;
}
