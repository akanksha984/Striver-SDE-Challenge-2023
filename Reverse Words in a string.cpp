string reverseString(string &str){
	// Write your code here.
	vector<string> words;
	int n= str.size();
	for (int i=0; i<n;){
		string word;
		while (i<n && str[i]!=' '){
			word+=str[i++];
		}
		if(!word.empty())words.push_back(word);
		while (i<n && str[i]==' ')i++;
	}	
	string ans;
	for (int i=words.size()-1; i>=0; i--){ans+= words[i]; ans+=' ';}
	return ans;
}
