#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,int>> q;
    int rot=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j]==2)q.push({i,j});
            if (grid[i][j]==1)rot++;
        }
    }
    if (q.empty()) return 0;
    int time=0;
    int dx[]= {-1,1,0,0};
    int dy[]= {0,0,1,-1};
    while (!q.empty()){
        int sz= q.size();
        while (sz--){
            int x= q.front().first;
            int y=q.front().second;
            q.pop();
            for (int it=0; it<4; it++){
                int nr= x+dx[it];
                int nc= y+dy[it];
                if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    rot--;
                }
            }
        }
        time++;
    }
    if (rot!=0)return -1;
    return time-1;
}
