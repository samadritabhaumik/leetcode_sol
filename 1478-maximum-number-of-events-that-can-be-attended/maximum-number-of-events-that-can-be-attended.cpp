class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int pos=0,time=1,attend=0;
        priority_queue<int,vector<int>,greater<int>> minheap;
        while(pos<n || !minheap.empty()){
            if(minheap.empty())
                time = max(time,events[pos][0]);
            while(pos<n && events[pos][0]==time){
                minheap.push(events[pos][1]);
                pos++;}
            while(!minheap.empty() && minheap.top()<time)
                minheap.pop();
            if(!minheap.empty()){
                minheap.pop();
                attend++;}
            time++;}
        return attend;
    }
};