class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=-1e18;
        long long prefix=0;
        int n=nums.size();
        vector<long long> mini(k,1e18);
        mini[k-1]=0;
        for (int i=0;i<n;i++) {
            prefix+=nums[i];
            int rem=i%k;
            if (i>=k-1) {
                ans=max(ans,prefix-mini[rem]);
            }
            if(i==k-1) {
            ans=prefix;
            }
            mini[rem]=min(mini[rem],prefix);
        }
        return ans;
    }
};