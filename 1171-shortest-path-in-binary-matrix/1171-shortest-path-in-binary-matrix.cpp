class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size() == 1 && grid[0][0] == 1)return -1;
        if(grid.size() == 1 && grid[0][0] == 0)return 1;
        if(grid[0][0] == 1)return -1;
        int n = grid.size();
        int dx[] = {0,1,1,1,0,-1,-1,-1};
        int dy[] = {-1,-1,0,1,1,1,0,-1};
        //(X)(X)(X)
        //(X)(11)(X)
        //(X)(X)(X)
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));\
        q.push({0,0});
        dist[0][0] = 1;
        while(!q.empty()){
            auto [r,c] = q.front();q.pop();
            for(int i=0;i<8;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0 && nr < n && nc >=0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] == 1e9){
                    dist[nr][nc] = dist[r][c]+1;
                    if(nr == n-1 && nc == n-1){
                        return dist[nr][nc];
                    }
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};