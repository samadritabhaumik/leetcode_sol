class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(i==nums1.size()){
           if(j==0){
            return -1e9;
           }
           return 0;
        }
        if(j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int skip = solve(i+1,j,nums1,nums2,dp);
        int pick =-1e9;
        for(int k =j;k<nums2.size();k++){
            pick = max(pick,nums1[i]*nums2[k]+solve(i+1,k+1,nums1,nums2,dp));
        }
        return dp[i][j]=max(pick,skip);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};