#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root){
    if (root==NULL)return false;
    if (!root->left && !root->right)return true;
    return false;
}
void leftTravel(TreeNode<int>* root, vector<int>& ans){
    if (!root)return;
    if (isLeaf(root))return;
    ans.push_back(root->data);
    if (root->left)leftTravel(root->left,ans);
    else if (root->right) leftTravel(root->right,ans);
}
void leaves(TreeNode<int>* root, vector<int>& ans){
    if (!root)return;
    if (isLeaf(root))ans.push_back(root->data);
    leaves(root->left,ans);
    leaves(root->right,ans);
}
void rightTravel(TreeNode<int>* root,vector<int>& temp){
    if (!root)return;
    if (isLeaf(root))return;
    temp.push_back(root->data);
    if (root->right)rightTravel(root->right,temp);
    else rightTravel(root->left,temp);

}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    // travel as left as you can;
    vector<int> ans;
    if (root==NULL)return ans;
    if (isLeaf(root))return {root->data};
    ans.push_back(root->data);
    leftTravel(root->left,ans);
    // leafs
    leaves(root->left,ans);
    leaves(root->right,ans);
    //right 
    vector<int> temp;
    rightTravel(root->right,temp);
    for (int i= temp.size()-1; i>=0; i--)ans.push_back(temp[i]);
    return ans;
}
