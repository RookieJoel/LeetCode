class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            if(grid[i][0] == 1) q.push({i,0});
            if(grid[i][n-1] == 1) q.push({i,n-1});
        }
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1) q.push({0,i});
            if(grid[m-1][i] == 1) q.push({m-1,i});
        }
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr = r +dx[i];
                int nc = c+dy[i];
                if(nr >=0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 69;
                    q.push({nr,nc});
                }
            }
        }
        int count = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};