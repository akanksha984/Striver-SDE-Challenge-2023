#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    if (root==NULL)return ans;
    map<int,vector<int>> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while (!q.empty()){
        TreeNode<int>* node= q.front().first;
        int vd= q.front().second;
        q.pop();
        mp[vd].push_back(node->data);
        if (node->left){
            q.push({node->left,vd-1});
        } 
        if (node->right){
            q.push({node->right,vd+1});
        }
    }
    for (auto val: mp){
        for (auto node: val.second)ans.push_back(node);
    }
    return ans;
}
