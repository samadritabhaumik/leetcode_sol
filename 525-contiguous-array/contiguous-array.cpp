class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int curr=0,res=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            curr+=(nums[i]==1)?1:-1;
           if(mp.find(curr)!=mp.end()){
            res=max(res,i-mp[curr]);
           }
           else mp[curr]=i;
        }
        return res;
    }
};