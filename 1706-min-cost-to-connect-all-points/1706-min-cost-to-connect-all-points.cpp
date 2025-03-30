class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n); //adj[points[i]] = {points[j],weight}
        vector<int> dist(n,1e9);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x = points[i][0];
                int y = points[i][1];
                int a = points[j][0];
                int b = points[j][1];
                int val = abs(x-a)+abs(y-b);
                adj[i].push_back({j,val});
                adj[j].push_back({i,val});
            }
        }
        dist[0] = 0;
        vector<int> visited(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});
        int total = 0;
        while(!pq.empty()){
            auto [weight,u] = pq.top();pq.pop();
           if(visited[u])continue;
           visited[u] = 1;
           total+=weight; 
            for(auto [v,w_uv] : adj[u]){
                if(!visited[v] && dist[v] > w_uv){
                        dist[v] = w_uv;
                        pq.push({dist[v],v});
                }
            }
        }

        return total;
    }
};
