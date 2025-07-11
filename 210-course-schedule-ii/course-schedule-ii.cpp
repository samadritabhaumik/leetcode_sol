class Solution {
public:
vector<int> topo(unordered_map<int,vector<int>>& adj,int n,vector<int> &indeg){
queue<int> q;
vector<int> res;
    int count=0;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
             res.push_back(i);
             count++;
            q.push(i);            
    }}
 while(!q.empty()){
        int u=q.front();
        q.pop();
    for(int &v:adj[u]){
        indeg[v]--;
        if(indeg[v]==0){
            res.push_back(v);
            count++;
            q.push(v);
        }
    } 
    }
if(count==n) return res;
return {};
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indeg(numCourses,0);
        for(auto &i:prerequisites){
            int a=i[0];
            int b=i[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        return topo(adj,numCourses,indeg);
    }
};