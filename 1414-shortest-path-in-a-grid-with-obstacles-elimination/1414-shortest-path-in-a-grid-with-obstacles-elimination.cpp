class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> step(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));

        queue<tuple<int,int,int,int>> q; // x, y, steps, remain
        q.push({0, 0, 0, k});
        step[0][0][k] = 0;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [x, y, steps, remain] = q.front(); q.pop();
            if (x == m-1 && y == n-1) return steps;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int next_remain = remain - grid[nx][ny];
                if (next_remain < 0) continue;

                if (step[nx][ny][next_remain] > steps + 1) {
                    step[nx][ny][next_remain] = steps + 1;
                    q.push({nx, ny, steps + 1, next_remain});
                }
            }
        }

        return -1;
    }
};
