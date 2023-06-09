/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool check(BinaryTreeNode<int>* one, BinaryTreeNode<int>* two){
    if (!one && !two)return true;
    if (one && !two)return false;
    if (!one && two)return false;
    if (one->data == two->data && check(one->left,two->right) && check(one->right,two->left))return true;
    return false;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    if (root==NULL)return true;
    return check(root->left,root->right);
}
