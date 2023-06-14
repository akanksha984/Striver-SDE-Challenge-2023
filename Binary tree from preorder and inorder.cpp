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

TreeNode<int>* dfs(vector<int>& ino, vector<int>& pre, int inStart,int inEnd, int preStart, int preEnd){
    if (inStart>inEnd || preStart>preEnd)return NULL;
    TreeNode<int>* curr= new TreeNode<int>(pre[preStart]);
    int loc= inStart;
    for (int i=inStart; i<=inEnd; i++){
        if (ino[i]==pre[preStart]){
            loc= i;
            break;
        }
    }
    int nums= loc-inStart;
    curr->left= dfs(ino,pre,inStart,loc-1,preStart+1,preStart+nums);
    curr->right= dfs(ino,pre,loc+1,inEnd,preStart+nums+1,preEnd);
    return curr;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n= inorder.size();
    if (n==0)return NULL;
    return dfs(inorder,preorder,0,n-1,0,n-1);
}
