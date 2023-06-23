#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* helper(int i, int j, vector<int>& arr){
    if (i<0|| j<0 || i>j)return NULL;
    if (i==j)return new TreeNode<int> (arr[i]);
    int mid= i+(j-i)/2;
    TreeNode<int>* head= new TreeNode<int> (arr[mid]);
    head->left = helper(i,mid-1,arr);
    head->right= helper(mid+1,j,arr);
    return head;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if (arr.empty())return NULL;
    //TreeNode<int>* head= new TreeNode<int> (arr[0]);
    return helper(0,n-1,arr);
}
