int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=1, j=0;
	while (i<n){
		if (arr[i]!=arr[i-1]){
			arr[j++]= arr[i];
		}
		i++;
	}
	return j+1;
}
