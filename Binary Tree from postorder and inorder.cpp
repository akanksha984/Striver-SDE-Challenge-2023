/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* dfs(vector<int>& ino, vector<int>& post, int inStart, int inEnd, int postStart, int postEnd){
     if (inStart>inEnd || postStart>postEnd)return NULL;
     TreeNode<int>* curr= new TreeNode<int>(post[postEnd]);
     int loc= inStart;
     for (int i=inStart; i<=inEnd; i++){
          if (ino[i]== post[postEnd]){
               loc= i;
               break;
          }
     }
     int nums= loc-inStart;
     curr->left= dfs(ino,post,inStart,loc-1,postStart,postStart+nums-1);
     curr->right= dfs(ino,post,loc+1,inEnd,postStart+nums,postEnd-1);
     return curr;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n= inOrder.size();
     if (n==0)return NULL;
     return dfs(inOrder,postOrder,0,n-1,0,n-1);
}
