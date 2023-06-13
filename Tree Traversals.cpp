#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inorder,preorder,postorder;
    if (root==NULL)return {inorder,preorder,postorder};
    stack<pair<BinaryTreeNode<int>*,int>> stk;
    stk.push({root,1});
    while (!stk.empty()){
        BinaryTreeNode<int>* node= stk.top().first;
        int num= stk.top().second;
        if (num==1){
            stk.pop();
            stk.push({node,2});
            preorder.push_back(node->data);
            if (node->left){
                stk.push({node->left,1});                
            }
        }
        else if (num==2){
            stk.pop();
            stk.push({node,3});
            inorder.push_back(node->data);
            if (node->right){
                stk.push({node->right,1});
            }
        }
        else{
            postorder.push_back(node->data);
            stk.pop();
        }
    }
    return {inorder,preorder,postorder};
}
