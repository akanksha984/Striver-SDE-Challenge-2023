#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long xx= x;
	long long ans=1;
	while (n>0){
		if (n&1){
			ans= (ans%m*xx%m)%m;
			n--;
		}
		else{
			xx= (xx%m*xx%m)%m;
			n= n>>1;
		}
	}
	return (int)(ans%m);
}
