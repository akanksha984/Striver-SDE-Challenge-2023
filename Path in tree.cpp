#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool dfs(TreeNode<int>* root, int x, vector<int>& ans){
	if (root==NULL)return false;
	if (root->data==x){
		ans.push_back(root->data);
		return true;
	}
	ans.push_back(root->data);
	if (dfs(root->left,x,ans))return true;
	else if (dfs(root->right,x,ans))return true;
	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	dfs(root,x,path);
	return path;
}
