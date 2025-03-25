class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //time[u][v] = weight
        vector<int> visited(n+1),dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
                int u = times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        dist[k] = 0;
        int ans = -1;
        while(!pq.empty()){
            auto [w,u] = pq.top();pq.pop();
            if(visited[u]) continue;
            visited[u] = 1;
            for(auto [v,wv] : adj[u]){
                if(!visited[v]){
                    if(dist[v] > dist[u]+wv){
                        dist[v] = dist[u]+wv;
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};