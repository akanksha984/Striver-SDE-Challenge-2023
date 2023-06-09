// https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	map<int,int> mp;
        pair<int, int> ans = { -1, -1 } ;
		for (int i = 0; i < n; i++) {
			mp[arr[i]]++;
		}
		for (int i=1; i<=n; i++){
			if (mp[i]==0)ans.first=i;
			if (mp[i]==2)ans.second=i;
		}
		return ans;
}



#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> v(n+1,0);
	pair<int,int> ans= {-1,-1};
	for (int i=0; i<n; i++){
		v[arr[i]]++;
	}
	for (int i=1; i<=n; i++){
		if (v[i]==0)ans.first= i;
		if (v[i]==2)ans.second=i;
	}
	return ans;
}



#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	/* vector<int> v(n+1,0);
	pair<int,int> ans= {-1,-1};
	for (int i=0; i<n; i++){
		v[arr[i]]++;
	}
	for (int i=1; i<=n; i++){
		if (v[i]==0)ans.first= i;
		if (v[i]==2)ans.second=i;
	}
	return ans; */
	pair<int,int> ans= {-1,-1};
	long long int currsq=0, actsq=0, currsm=0, actsm=0;
	for (int i=0; i<n; i++){
		currsm+= arr[i];
		currsq+= (long long int)(arr[i]*arr[i]);
	}
	actsm= (long long int)(n*(n+1))/2;
	actsq= ((long long int)n*(long long int)(n+1)*(long long int)(2*n+1))/6;
	long long int d2= actsq-currsq;
	long long int d1= actsm-currsm;
	long long int missing= (d2+ (d1*d1))/(2*d1);
	long long int repeat= missing-d1;
	ans= {missing,repeat};
	return ans;
}

