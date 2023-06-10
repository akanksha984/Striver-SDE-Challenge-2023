#include <queue>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n= edges.size();
	vector<int> color(n,-1);
	vector<int> adjNodes[n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (edges[i][j]==1)adjNodes[i].push_back(j);
		}
	}
	for (int i=0; i<n; i++){
		if (color[i]== -1){
			int curr=0;
			queue<int> q;
			q.push(i);
			color[i]=1;
			while (!q.empty()){
				int sz= q.size();
				while (sz--){
					int node= q.front();
					q.pop();
					for (auto adj: adjNodes[node]){
						if (color[adj]==-1){
							color[adj]= curr;
							q.push(adj);
						}
						else if (color[adj]==color[node]){
							return false;
						}
					}

				}
				curr= !curr;
			}
		}
	}
	return true;
}
