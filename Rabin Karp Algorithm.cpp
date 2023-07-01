vector<int> find_pi(string& s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[j]!=s[i]){
            j = pi[j-1];
        }
        if(s[j]==s[i])
            j++;   
        pi[i] = j;
    }
    return pi;
}


vector<int> stringMatch(string &str, string &pat) {
    int n = pat.size();
    string tot = pat+'$'+str;
    vector<int> pi = find_pi(tot);
    vector<int> ans;
    for(int i=0; i<pi.size(); i++){
        if(pi[i] == n){
            ans.push_back(1+i-(2*n));
        }
    }

    return ans;
    
}
