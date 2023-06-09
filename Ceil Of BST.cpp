#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void check(BinaryTreeNode<int>* node, int x, int& ans){
    if (node==NULL)return;
    if (node->data == x){
        ans= x;
        return;
    }
    else if (node->data < x){
        check(node->right,x,ans);
    }
    else{
        ans= node->data;
        check(node->left,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans= -1;
    check(node,x,ans);
    return ans;
}
