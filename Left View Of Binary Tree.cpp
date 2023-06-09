#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    if (root==NULL)return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()){
        int sz= q.size();
        bool found=0;
        for (int i=0; i<sz; i++){
            TreeNode<int>* curr= q.front();
            q.pop();
            if (!found){
                found=1;
                ans.push_back(curr->data);
            }
            if (curr->left)q.push(curr->left);
            if (curr->right)q.push(curr->right);
        }
        
    }
    return ans;
}
