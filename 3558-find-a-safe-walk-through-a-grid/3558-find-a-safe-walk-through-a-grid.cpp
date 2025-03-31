class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MIN));
        if(grid[0][0] == 1) health--;
        priority_queue<tuple<int,int,int>> pq;
        pq.push({health,0,0});
        dist[0][0] = health;
        while(!pq.empty()){
            auto [w,r,c] = pq.top();pq.pop();
            for(int i=0;i<4;i++){
                int nr = r +dx[i];
                int nc = c+dy[i];
                if(nr >= 0 && nr < m && nc >=0 && nc < n){
                    if(dist[nr][nc] < dist[r][c] - grid[nr][nc]){
                        dist[nr][nc] = dist[r][c] - grid[nr][nc];
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return dist[m-1][n-1] > 0;
    }
};