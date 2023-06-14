#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* dfs(vector<int>& preOrder, int& i, int bound){
    if (i==preOrder.size() || preOrder[i]>bound)return NULL;
    TreeNode<int>* node= new TreeNode<int>(preOrder[i++]);
    node->left= dfs(preOrder,i,node->data);
    node->right= dfs(preOrder,i,bound);
    return node;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    if (preOrder.size()==0)return NULL;
    int i=0;
    return dfs(preOrder,i,INT_MAX);
}
