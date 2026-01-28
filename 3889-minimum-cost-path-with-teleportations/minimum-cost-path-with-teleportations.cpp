class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        long long inf = 1e16; 
        vector<vector<vector<long long>>> f(k+1,vector<vector<long long>>(m,vector<long long>(n,inf)));
        f[0][0][0]=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) f[0][i][j] = min(f[0][i][j], f[0][i - 1][j] + grid[i][j]);
                if (j > 0) f[0][i][j] = min(f[0][i][j], f[0][i][j - 1] + grid[i][j]);
            }
        }
        map<int, vector<pair<int, int>>> val_to_cells;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                val_to_cells[grid[i][j]].push_back({i, j});
            }
        }
        vector<int> sorted_values;
        for (auto const& [val, cells] : val_to_cells) sorted_values.push_back(val);
        sort(sorted_values.rbegin(), sorted_values.rend());
        for (int t = 1; t <= k; ++t) {
            long long min_prev_cost = inf;
            for (int val : sorted_values) {
                for (auto& p : val_to_cells[val]) {
                    min_prev_cost = min(min_prev_cost, f[t - 1][p.first][p.second]);
                }
                for (auto& p : val_to_cells[val]) {
                    f[t][p.first][p.second] = min_prev_cost;
                }
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) f[t][i][j] = min(f[t][i][j], f[t][i - 1][j] + grid[i][j]);
                    if (j > 0) f[t][i][j] = min(f[t][i][j], f[t][i][j - 1] + grid[i][j]);
                }
            }
        }
        long long ans = inf;
        for (int t = 0; t <= k; ++t) {
            ans = min(ans, f[t][m - 1][n - 1]);
        }
        return (int)ans;
    }
};