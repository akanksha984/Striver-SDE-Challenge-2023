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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> stk;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        stk.push(root);
        while (root->left){
            stk.push(root->left);
            root= root->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int>* node= stk.top();
        stk.pop();
        if (node->right){
            TreeNode<int>* temp= node->right;
            while (temp){
                stk.push(temp);
                temp= temp->left;
            }
        }
        return node->data;
    }

    bool hasNext()
    {
        // write your code here
        return (!stk.empty());
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
