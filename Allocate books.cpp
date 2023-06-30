#include <bits/stdc++.h> 
bool allocate(vector<int>& time, int days, long long int curr){
	long long int cnt=1;
	long long int summ=0;
	for (int i=0; i<time.size(); i++){
		if (time[i]+summ<=curr){
			summ+= time[i];
		}
		else{
			cnt++;
			if (time[i]>curr || cnt>days)return false;
			summ=time[i];
		}
	}
	return true; //(cnt<=days);
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	
	long long int s= 0;
	long long int e=0;
	for (int i=0; i<time.size(); i++)e+= time[i];
	long long int ans= 0;
	while (s<=e){
		long long int mid= s+(e-s)/2;
		if (allocate(time,n,mid)){
			ans= mid;
			e= mid-1;
		}
		else{
			s= mid+1;
		}
	}
	return ans;
}
