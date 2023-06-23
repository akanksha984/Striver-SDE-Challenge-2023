#include <bits/stdc++.h> 
class DisjointSet{
	public:
		vector<int> par,size;
		DisjointSet(int n){
			par.resize(n+1,0);
			size.resize(n+1,1);
			for (int i=0; i<=n; i++)par[i]=i;
		}	
		int findUPar(int u){
			if (par[u]==u)
				return u;
			return par[u]= findUPar(par[u]);
		}
		void unionBySize(int u, int v){
			int ulp_u= findUPar(u);
			int ulp_v= findUPar(v);
			if (ulp_v==ulp_u)return ;
			if (size[ulp_u]>size[ulp_v]){
				par[ulp_v]=ulp_u;
				size[ulp_u]+= size[ulp_v];
			}
			else{
				par[ulp_u]=ulp_v;
				size[ulp_v]+= size[ulp_u];
			}
		}
};



bool comp(vector<int>& a, vector<int>& b){
	return a[2]<=b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	int sm=0;
	DisjointSet ds(n);
	sort(graph.begin(),graph.end(),comp);
	for (auto val: graph){
		int u= val[0]; int v= val[1];
		int wt= val[2];
		if (ds.findUPar(u)==ds.findUPar(v))continue;
		sm+= wt;
		ds.unionBySize(u,v);
	}
	return sm;
}
