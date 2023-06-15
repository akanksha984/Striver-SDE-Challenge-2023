#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class Node{
    public:
    int minNode,maxNode,size;
    Node(int minNode,int maxNode,int size){
        this->minNode= minNode;
        this->maxNode= maxNode;
        this->size= size;
    }
};
Node helper(TreeNode<int>* root){
    if (root==NULL){
        return {INT_MAX,INT_MIN,0};
    }
    Node left_val=helper(root->left);
    Node right_val=helper(root->right);

    if (left_val.maxNode < root-> data && right_val.minNode > root->data){
        return {min(left_val.minNode,root->data),max(root->data,right_val.maxNode),left_val.size+right_val.size+1};
    }

    return {INT_MIN,INT_MAX,max(left_val.size,right_val.size)};
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return helper(root).size;
}
