class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
  
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,count,m,n,grid);
                }
            }
        }

        return count;
        
    }
    void dfs(int i,int j,int &count,int m,int n,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        count++;
        q.push({i,j});
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(grid[nr][nc] == '1'){
                        grid[nr][nc] = 'x';
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};