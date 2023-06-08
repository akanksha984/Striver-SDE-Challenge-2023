// https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int req= n/2;
	map<int,int> mp;
	for (int i=0; i<n; i++){
		mp[arr[i]]++;
		if (mp[arr[i]]>req)return arr[i];
	}
	return -1;
}
