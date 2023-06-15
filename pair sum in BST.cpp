#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTIterator{
    public:
    stack<BinaryTreeNode<int>*> stk; bool rev;
    BSTIterator(BinaryTreeNode<int>* root, bool rev){
        this->rev= rev;
        stk.push(root);
        pushAll(root,rev);
    }
    void pushAll(BinaryTreeNode<int>* root,bool rev){
        if (rev){
            root= root->right;
            while (root){
                stk.push(root);
                root= root->right;
            }
        }
        else{
            root= root->left;
            while (root){
                stk.push(root);
                root= root->left;
            }
        }
    }
    int next(){
        BinaryTreeNode<int>* node= stk.top();
        stk.pop();
        if (rev){
            if (node->left){
                stk.push(node->left);
                pushAll(node->left,rev);
            }
        }
        else{
            if (node->right){
                stk.push(node->right);
                pushAll(node->right,rev);
            }
        }
        return node->data;
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i= l.next();
    int j= r.next();
    while (i<j){
        if (i+j == k)return 1;
        if (i+j > k){
            j= r.next();
        }
        else i= l.next();
    }
    return 0;
}
