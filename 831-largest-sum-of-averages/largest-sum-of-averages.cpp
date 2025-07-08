class Solution {
public:
double dp[105][105];
double solve(vector<int>& nums,int n, int k){
    if(n>=nums.size() || k<0) return 0;
    if(k==0){
        return INT_MIN;
    }
    if (dp[n][k]!=0) return dp[n][k];
    double sum=0,ans=0;
    for(int i=n;i<nums.size();i++){
        sum+=nums[i];
        ans=max(ans,sum/(i-n+1)+solve(nums,i+1,k-1));
    }
    return dp[n][k]=ans;
}
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        return solve(nums,0,k);
    }
};