class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, path, ans);
        return ans;
    }

    void dfs(int u, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans) {
        path.push_back(u);
        if (u == graph.size() - 1) {
            ans.push_back(path);
        } else {
            for (int v : graph[u]) {
                dfs(v, graph, path, ans);
            }
        }
        path.pop_back(); 
    }
};
