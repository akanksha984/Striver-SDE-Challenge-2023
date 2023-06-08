// https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	set<int> st;
	for (int i=0; i<n; i++){
		if (st.find(arr[i])==st.end()){
			st.insert(arr[i]);
		}
		else return arr[i];
	}
	return -1;
}
