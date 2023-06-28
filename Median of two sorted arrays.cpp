double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1= a.size(); int n2= b.size();
	if (n2<n1)return median(b,a);
	int n= n1+n2;
	int i=0; int j= n1;
	while (i<=j){
		int cut1= i+(j-i)/2;
		int cut2= (n+1)/2-cut1;
		int l1= INT_MIN, l2= INT_MIN, r1= INT_MAX, r2= INT_MAX;
		if (cut1!=0)l1= a[cut1-1];
		if (cut1!=n1)r1=a[cut1];
		if (cut2!=0)l2= b[cut2-1];
		if (cut2!=n2)r2=b[cut2];
		if (l1<=r2 && l2<=r1){
			if (n%2==0){
				return (double)((double)min(r1,r2)+(double)max(l1,l2))/(2.0);
			}
			else{
				return max(l1,l2);
			}
		}
		else if (l1>r2){
			j= cut1-1;
		}
		else{
			i= cut1+1;
		}
	}
}
