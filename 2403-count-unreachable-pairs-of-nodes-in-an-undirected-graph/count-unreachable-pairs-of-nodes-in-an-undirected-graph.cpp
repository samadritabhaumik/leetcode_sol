class Solution {
public:
void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool>& visited, long long &comp) {
        visited[u] = true;
        comp++;
        for(int &v:adj[u]) { 
            if(!visited[v]) {
                dfs(v,adj,visited,comp);
            }}}
    long long countPairs(int n, vector<vector<int>>& edges) {
         unordered_map<int, vector<int>> adj;
        for(auto &vec : edges){
            int u=vec[0];
            int v=vec[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        long long remaining=n;
        long long res=0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                long long comp = 0;
                dfs(i, adj, visited, comp);
                res += (comp) * (remaining-comp);
                remaining-=comp;       
            }
        }
        return res;
    }
};