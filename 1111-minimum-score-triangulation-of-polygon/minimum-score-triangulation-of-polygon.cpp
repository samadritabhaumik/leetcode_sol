class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
         int n = (int)values.size();
        if (n < 3) return 0;
        const long long INF = (1LL<<60);
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                long long best = INF;
                for (int k = i + 1; k < j; ++k) {
                    long long cost=dp[i][k]+dp[k][j]+1LL*values[i] * values[k] * values[j];
                    if (cost < best) best = cost;
                }
                dp[i][j] = (best == INF ? 0 : best);
            }
        }
        return (int)dp[0][n-1];
    }
};