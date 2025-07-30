class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int n=nums.size();
        int maxm=*max_element(nums.begin(),nums.end());
        int maxi=0,cur=0;
        for(int i=0;i<n;++i){
            if(nums[i]==maxm){
                cur++;
                if(maxi<cur)
                    maxi=cur;
            }else{
                cur=0;
            }}
        return maxi;
    }
};