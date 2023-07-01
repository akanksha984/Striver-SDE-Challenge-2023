int zAlgorithm(string haystack, string needle, int n, int m)
{
	// Write your code here
        int h_size = haystack.size();
        int n_size = needle.size();
        int size = haystack.size()/needle.size();
        int count = 0;
        for(int i=0; i<h_size; i++) {
            if(needle == haystack.substr(i,n_size)) {
                count++;
            }
        }
        return count;
}
