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
#include <bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
 string ans;
 if (root==NULL)return ans;
 queue<TreeNode<int>*> q;
 q.push(root);
 ans+= to_string(root->data);
 ans+=',';
 while (!q.empty()){
     TreeNode<int>* curr= q.front();
     q.pop();

     if (curr->left){
         q.push(curr->left);
         ans+= to_string(curr->left->data);
     }
     else ans+='#';
     ans+=',';
     if (curr->right){
         q.push(curr->right);
         ans+= to_string(curr->right->data);
     }
     else ans+='#';
     ans+=',';
 }
 return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
 if (serialized=="")return NULL;
 stringstream s(serialized);
 string str;
 getline(s,str,',');
 TreeNode<int>* head= new TreeNode<int>(stoi(str));
 queue<TreeNode<int>*> q;
 q.push(head);
 while (!q.empty()){
     TreeNode<int>* node= q.front();
     q.pop();
     getline(s,str,',');
     if (str=="#"){
         node->left= NULL;
     }
     else{
         node->left= new TreeNode<int>(stoi(str));
         q.push(node->left);
     }
     getline(s,str,',');
     if (str=="#"){
         node->right= NULL;
     }
     else{
         node->right= new TreeNode<int>(stoi(str));
         q.push(node->right);
     }
 } 
    return head;
}



