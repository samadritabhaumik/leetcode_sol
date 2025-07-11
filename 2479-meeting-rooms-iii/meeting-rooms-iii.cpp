class Solution {
    #define ll long long
    #define pli pair<ll,int>
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pli,vector<pli>,greater<pli>> free, occupied;
        vector<int> freq(n,0);
        for(int i=0;i<n;++i)
            free.push({0,i});
        for(int i=0;i<meetings.size();++i){
            while(!occupied.empty() and occupied.top().first<=meetings[i][0]){
                pli curr = occupied.top();
                occupied.pop();
                curr.first = 0;
                free.push(curr);
            }
            if(!free.empty()){
                pli curr = free.top();
                free.pop();
                freq[curr.second]++;
                curr.first = meetings[i][1];
                occupied.push(curr);
            }else{
                pli curr = occupied.top();
                occupied.pop();
                freq[curr.second]++;
                curr.first += 1LL*(meetings[i][1] - meetings[i][0]);
                occupied.push(curr);
            }
        }
        int maxi,maxm = 0;
        for(int i=0;i<n;++i){
            if(freq[i]>maxm){
                maxi = i;
                maxm = freq[i];
            }
        }
        return maxi;
    }
};
