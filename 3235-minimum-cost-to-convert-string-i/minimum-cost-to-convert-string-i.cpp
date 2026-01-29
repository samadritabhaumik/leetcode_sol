class Solution {
public:
    void dijistra(int source,vector<pair<int,int>> adj[],vector<vector<int>> &dis){
        dis[source][source]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,source});
        while(!q.empty()){
            int node = q.top().second;
            q.pop();
            for(auto i: adj[node]){
                int ne = i.second;
                int wt = i.first;
                if(dis[source][ne]>dis[source][node]+wt){
                    dis[source][ne]=dis[source][node]+wt;
                    q.push({dis[source][ne],ne});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>> adj[26];
        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            adj[u].push_back({cost[i],v});
        }
        vector<vector<int>> dis(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            dijistra(i,adj,dis);
        }
        long long ans =0;
        for(int i=0;i<source.size();i++){
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(dis[u][v]!=1e9){
                ans+=dis[u][v];
            }else{
                return -1;
            }
        }
        return ans;
    }
};