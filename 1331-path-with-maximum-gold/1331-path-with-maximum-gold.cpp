class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int ans = 0;
    int totalGold = 0; // gold à¸à¸±à¹à¸à¸«à¸¡à¸à¹à¸ grid

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        totalGold = 0;
        for (auto& row : grid)
            for (int gold : row)
                totalGold += gold;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    dfs(grid, visited, i, j, 0);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int total) {
        total += grid[r][c];
        ans = max(ans, total);

        visited[r][c] = true;
        int m = grid.size(), n = grid[0].size();

        // "bound": à¸à¹à¸² total + gold à¸à¸µà¹à¹à¸«à¸¥à¸·à¸­à¹à¸ grid < ans => à¸à¸±à¸à¸à¸´à¹à¸
        int remainingGold = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j])
                    remainingGold += grid[i][j];
        if (total + remainingGold <= ans) {
            visited[r][c] = false;
            return; // prune branch
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                dfs(grid, visited, nr, nc, total);
            }
        }

        visited[r][c] = false;
    }
};
