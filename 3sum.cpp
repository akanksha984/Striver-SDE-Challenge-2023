#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for (int i=0; i<n-2; i++){
		if (i==0 || arr[i]!= arr[i-1]){
			int j= i+1, k= n-1;
			while (j<k){
				if (arr[i]+arr[j]+arr[k]== K){
					ans.push_back({arr[i],arr[j],arr[k]});
					int curr_j= arr[j], curr_k= arr[k];
					while (arr[j]==curr_j)j++;
					while (arr[k]==curr_k)k--;
				}
				else if (arr[i]+arr[j]+arr[k] < K){
					j++;
				}
				else{
					k--;
				}
			}	
		}
		
	}
	return ans;
}
