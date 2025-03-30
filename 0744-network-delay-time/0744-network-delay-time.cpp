class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        dist[k] = 0;
        q.push({0,k});
        while(!q.empty()){
            auto [w,u] = q.top();q.pop();
            for(auto [v,w_uv] : adj[u]){
                if(dist[v] > dist[u]+w_uv){
                    dist[v] = dist[u]+w_uv;
                    q.push({dist[v],v});
                }
            }
        }
        int ans = -2;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};