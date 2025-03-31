class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [w,r,c] = pq.top();pq.pop();
            if(r == n-1 && c == m-1) return w;
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m){
                    if(dist[nr][nc] > dist[r][c]+moveTime[nr][nc]+1){
                        int diff = max(dist[r][c],moveTime[nr][nc])+1;
                        if(diff < dist[nr][nc]){
                            dist[nr][nc] = diff;
                            pq.push({dist[nr][nc],nr,nc});
                        }
                    }
                }
            }
        }
        return -1;
    }
};