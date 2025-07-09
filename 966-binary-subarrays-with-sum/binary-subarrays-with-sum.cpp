class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int curr=0,res=0;
        mp[0]=1;
        for(int &num:nums){
            curr+=num;
            int rem=curr-goal;
            if(mp.find(rem)!=mp.end()){
                res+=mp[rem];
            }
            mp[curr]++;
        }
        return res;
    }
};