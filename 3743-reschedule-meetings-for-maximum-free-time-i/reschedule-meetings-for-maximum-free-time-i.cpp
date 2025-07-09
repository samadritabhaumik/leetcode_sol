class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        if(eventTime>endTime.back()){
            startTime.push_back(eventTime);
            endTime.push_back(eventTime);
        }
        int n=startTime.size();
        int maxi=0,win=0,pos = 0,last = 0;
        deque<int> dq;
        while(pos<n){
            win += (startTime[pos]-last);
            maxi=max(maxi,win);
            dq.push_back(startTime[pos]-last);
            if(dq.size()>k){
                win -= dq.front();
                dq.pop_front();
            }
            last=endTime[pos];
            pos++;
        }
        return maxi;
    }
};