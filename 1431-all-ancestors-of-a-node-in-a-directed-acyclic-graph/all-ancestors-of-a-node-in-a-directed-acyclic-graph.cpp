class Solution {
public:
void dfs(int anc,unordered_map<int,vector<int>>& mp,int curr,vector<vector<int>>& res){
    for(int &i:mp[curr]){
        if(res[i].empty() || res[i].back()!=anc){
            res[i].push_back(anc);
            dfs(anc,mp,i,res);
        }
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> res(n);
    for(vector<int>& i:edges){
        int a=i[0];
        int b=i[1];
        mp[a].push_back(b);
    }
    for(int j=0;j<n;j++){
        int anc=j;
        dfs(anc,mp,j,res);
    }
    return res;
    }
};