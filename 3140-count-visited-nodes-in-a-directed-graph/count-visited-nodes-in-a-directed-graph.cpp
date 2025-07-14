class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> reverseGraph(n); 
        vector<int> indegree(n, 0);
        vector<int> visited(n, 0);
        vector<int> ans(n, 0);
        for (int u = 0; u < n; u++) {
            int v = edges[u];
            reverseGraph[v].push_back(u);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited[node] = 1;
            int next = edges[node];
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int curr = i;
                vector<int> cycle;
                while (!visited[curr]) {
                    visited[curr] = 1;
                    cycle.push_back(curr);
                    curr = edges[curr];
                }
                int size = cycle.size();
                for (int node : cycle) {
                    ans[node] = size;
                }
            }
        }
        function<int(int)> dfs = [&](int node) -> int {
            if (ans[node]) return ans[node];
            int maxChild = dfs(edges[node]);
            return ans[node] = maxChild + 1;
        };
    for(int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                dfs(i);
            }}
        return ans;
    }
};
