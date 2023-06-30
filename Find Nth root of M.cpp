double check(int num, int p){
  double ans= 1;
  while (p--){
    ans*= num;
  }
  return ans;
}
int NthRoot(int n, int m) {
  // Write your code here.
  double i=1, j=m;
  while (i<=j){
    int mid= i+(j-i)/2;
    double curr= check(mid,n);
    if (curr==m){
      return mid;
    }
    else if (curr>m){
      j= mid-1;
    }
    else{
      i= mid+1;
    }
  }
  return -1;
}
