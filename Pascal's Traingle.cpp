// CODESTUDIO
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  ans.push_back({1});
  for (int i=1; i<n; i++){
    vector<long long int> temp;
    temp.push_back(1);
    for (int j=1; j<ans[i-1].size(); j++){
      temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
    }
  temp.push_back(1);
  ans.push_back(temp);
  }
  return ans;

}

//LEETCODE
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=1; i<numRows; i++){
            vector<int> temp;
            temp.push_back(1);
            for (int j=1; j<ans[i-1].size(); j++){
                temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
