 class Solution {
    #define pii pair<int,int>
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> dist(n,vector<int>(2,-1));
        dist[node1][0]=0;
        dist[node2][1]=0;
        queue<pii> q;
        q.push({node1,0});
        q.push({node2,1});
        while(!q.empty()){
            auto& [curr,type] = q.front();
            if(edges[curr]!=-1 and dist[edges[curr]][type]==-1){
                dist[edges[curr]][type] = 1 + dist[curr][type];
                q.push({edges[curr],type});
            }
            q.pop();
        }
        int mp = INT_MAX;
        int meeting_distance = INT_MAX;
        for(int i=0;i<n;++i){
            if(dist[i][0]!=-1 and dist[i][1]!=-1){
                int curr_dist = max(dist[i][0],dist[i][1]);
                if(curr_dist < meeting_distance){
                    meeting_distance = curr_dist;
                    mp = i;
                }
                }
        }
        return mp==INT_MAX?-1:mp;
    }
};