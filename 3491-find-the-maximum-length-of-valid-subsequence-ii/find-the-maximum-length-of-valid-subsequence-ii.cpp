class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ans(k,vector<int>(k));
        int maxi = 0;
        for(int i=0;i<n;++i){
            int curr=nums[i]%k;
            for(int prev=0;prev<k;++prev){
                ans[curr][prev]=ans[prev][curr] + 1;
                maxi=max(maxi,ans[curr][prev]);
            }
        }
        return maxi;
    }
};