class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for(int i = 0; i <= k; ++i){
            vector<int> temp = dist;
            for(int u = 0; u < n; ++u){
                if(dist[u] == 1e9) continue;
                for(auto [v, w] : adj[u]){
                    if(temp[v] > dist[u] + w){
                        temp[v] = dist[u] + w;
                    }
                }
            }
            dist = temp;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
