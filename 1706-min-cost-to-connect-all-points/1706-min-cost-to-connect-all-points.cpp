class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n); //adj[points[i]] = {points[j],weight}
        vector<int> dist(n,INT_MAX),visited(n);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});
        int total = 0;
        while(!pq.empty()){
            auto [w,pi] = pq.top();pq.pop();
            if(visited[pi]) continue;
            visited[pi] = 1;
            total += w;
            for(int i=0;i<n;i++){
                if(i == pi)continue;
                int dif = abs(points[pi][0] - points[i][0]) + abs(points[pi][1] - points[i][1]);
                if(dist[i] > dif){
                    dist[i] = dif;
                    pq.push({dif,i});
                }
            }
        }
        return total;
        
    }
};
