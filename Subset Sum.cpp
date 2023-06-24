void helper(int i, int sm, vector<int>& num, vector<int>& ans){
	//ans.push_back(sm);
	if (i==num.size()){
		ans.push_back(sm);
		return;
	}
	//notPick= 
	helper(i+1,sm,num,ans);
	//pick= 
	helper(i+1,sm+num[i],num,ans);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> ans;
	helper(0,0,num,ans);
	sort(ans.begin(),ans.end());
	return ans;
}
