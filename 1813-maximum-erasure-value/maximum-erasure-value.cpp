class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start=0,end=0,n=nums.size(),sum=0,ans=0;
        set<int> s;
        while(end<n){
            while(start<end && s.find(nums[end])!=s.end()){
            s.erase(nums[start]);
            sum-=nums[start++];
            }
            s.insert(nums[end]);
            sum+=nums[end++];
            ans=max(ans,sum);
        }
        return ans;
    }
};