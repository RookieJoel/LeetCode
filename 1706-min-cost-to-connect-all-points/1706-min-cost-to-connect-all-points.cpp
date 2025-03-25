class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        set<pair<int, int>> pq; // {cost, node}

        minDist[0] = 0;
        pq.insert({0, 0});
        int totalCost = 0;

        while (!pq.empty()) {
            auto [cost, u] = *pq.begin();
            pq.erase(pq.begin());

            if (visited[u]) continue;
            visited[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        pq.erase({minDist[v], v}); 
                        minDist[v] = dist;
                        pq.insert({dist, v});
                    }
                }
            }
        }

        return totalCost;
    }
};
