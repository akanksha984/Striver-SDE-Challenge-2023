#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if (root==NULL)return ans;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    mp[0]= root->data;
    while (!q.empty()){
        BinaryTreeNode<int>* node= q.front().first;
        int ind= q.front().second;
        q.pop();
        mp[ind]= node->data;
        if (node->left)q.push({node->left,ind-1});
        if (node->right)q.push({node->right,ind+1});
    }
    for (auto vl: mp){
        ans.push_back(vl.second);
    }
    return ans;
}
