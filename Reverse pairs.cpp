#include <bits/stdc++.h> 
int merge(vector<int>& arr,int low, int mid, int high){
	int cnt=0, j= mid+1;	// j points to right half
	for (int i=low; i<=mid; i++){
		while (j<=high && arr[i]>(2*arr[j])){
			j++;
		}
		cnt+= (j-(mid+1));
	}
	// merge function
	vector<int> temp;
	int left= low, right= mid+1; 
	while (left<=mid && right<=high){
		if (arr[left]<arr[right]){
			temp.push_back(arr[left++]);
		}
		else temp.push_back(arr[right++]);
	}
	while (left<=mid){
		temp.push_back(arr[left++]);
	}
	while (right<=high){
		temp.push_back(arr[right++]);
	}
	for (int i=low; i<=high; i++){
		arr[i]= temp[i-low];
	}
	return cnt;
}
int mergeSort(int i, int j, vector<int>& arr){
	if (i>=j)return 0;
	int mid= i+(j-i)/2;
	int inv= 0;
	inv+= mergeSort(i,mid,arr);
	inv+= mergeSort(mid+1,j,arr);
	inv+= merge(arr,i,mid,j);
	return inv;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergeSort(0,n-1,arr);
}
