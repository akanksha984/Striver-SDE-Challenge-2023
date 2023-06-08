// CODESTUDIO SOLUTION:
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n= matrix.size(); int m= matrix[0].size();
	vector<int> rows(n,0),cols(m,0);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (matrix[i][j]==0){
				rows[i]=1;
				cols[j]=1;
			}
		}
	}
	for (int i=0; i<n; i++){
		if (rows[i]==1){
			for (int j=0; j<m; j++)matrix[i][j]=0;
		}
	}
	for (int i=0; i<m; i++){
		if (cols[i]==1){
			for (int j=0; j<n; j++)matrix[j][i]=0;
		}
	}
}


// LEETCODE SOLUTION
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> rows(n,0),cols(m,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for (int i=0; i<n; i++){
            if (rows[i]==1){
                for (int j=0; j<m; j++){
                    matrix[i][j]=0;
                }
            }
        }
        for (int i=0; i<m; i++){
            if (cols[i]==1){
                for (int j=0; j<n; j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
};
