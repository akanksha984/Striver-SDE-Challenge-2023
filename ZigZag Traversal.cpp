

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    bool rev= false;
    if (root==NULL)return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()){
        int sz= q.size();
        vector<int> temp;
        for (int i=0; i<sz; i++){
            BinaryTreeNode<int>* curr= q.front();
            q.pop();
            temp.push_back(curr->data);
            if (curr->left)q.push(curr->left);
            if (curr->right)q.push(curr->right);
        }
        if (rev){
            for (int i= temp.size()-1; i>=0; i--)ans.push_back(temp[i]);
        }
        else{
            for (int i=0; i<temp.size(); i++)ans.push_back(temp[i]);
        }
        rev= !rev;
    }
    return ans;
}
