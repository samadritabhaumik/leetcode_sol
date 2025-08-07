class Solution {
    using ll = long long;
    static constexpr int INF = std::numeric_limits<int>::max();
    int dfs(const vector<vector<int>>& fruits,
            int row,int col,int moves,
            vector<vector<int>>& mem,
            const vector<pair<int,int>>& dirs)
    {
        int n = fruits.size();
        if (row == n-1 && col == n-1)   
            return moves == 0 ? 0 : INF;
        if (moves == 0 || row == col)   
            return INF;
        if (mem[row][col] != -1)       
            return mem[row][col];
        ll maxi = -1;
        for (auto [dr, dc] : dirs) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                int val = dfs(fruits, nr, nc, moves-1, mem, dirs);
                if (val != INF)
                    maxi = max(maxi, (ll)val);
            }
        }
        return mem[row][col] = (maxi < 0 ? INF : fruits[row][col] + maxi);}
    public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        ll first = 0;
        for (int i = 0; i < n; ++i)
            first += fruits[i][i];
        vector<pair<int,int>> down={{1,-1},{1,0},{1,1}};
        vector<vector<int>> mem(n, vector<int>(n, -1));
        int second = dfs(fruits, 0, n-1, n-1, mem, down);
        vector<pair<int,int>> right = {{-1,1},{0,1},{1,1}};
        for (auto& row : mem) fill(row.begin(), row.end(), -1);
        int third = dfs(fruits, n-1, 0, n-1, mem, right);
        return first + second + third;
    }
};