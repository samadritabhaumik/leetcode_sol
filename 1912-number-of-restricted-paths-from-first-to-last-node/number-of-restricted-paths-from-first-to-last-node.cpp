class Solution {
public:
    int mod = 1e9 + 7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e:edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,n});
        while(!pq.empty()) {
            auto [d,u]=pq.top();pq.pop();
            if (d>dist[u]) continue;
            for (auto& edge:adj[u]) {
                int v=edge.first, w=edge.second;
                if (dist[v]>d+w) {
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }}}
        vector<int> dp(n+1,-1);
        function<int(int)> dfs=[&](int u) {
            if (u == n) return 1;
            if (dp[u]!=-1) return dp[u];
            int ans=0;
            for (auto& edge:adj[u]) {
                int v=edge.first;
                if (dist[v]<dist[u]) {
                    ans=(ans+dfs(v))%mod;
                }
            }
            return dp[u]=ans;
        };
        return dfs(1);
    }
};
