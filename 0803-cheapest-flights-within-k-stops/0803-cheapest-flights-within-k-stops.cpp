class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].push_back({v, w});
        }

        // {cost, current city, stops used}
        queue<tuple<int, int, int>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, src, 0});
        dist[src] = 0;

        while (!q.empty()) {
            auto [cost, city, stops] = q.front(); q.pop();

            if (stops > k) continue;

            for (auto [nei, price] : adj[city]) {
                if (cost + price < dist[nei]) {
                    dist[nei] = cost + price;
                    q.push({dist[nei], nei, stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
