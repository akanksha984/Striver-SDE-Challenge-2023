string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string pref="";
    int len= 1e5;
    for (int i=0; i<n; i++){
        if (len > arr[i].size()){
            len= arr[i].size();
        }
    }
    for (int i=0; i<len; i++){
        for (int j=1; j<n; j++){
            if (arr[j][i]!= arr[0][i])return pref;
        }
        pref+= arr[0][i];
    }
    return pref;
}


