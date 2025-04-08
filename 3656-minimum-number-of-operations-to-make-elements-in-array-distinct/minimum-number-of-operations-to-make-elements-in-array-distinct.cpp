class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         vector<bool> ans(128);
        for (int i=nums.size()-1; i>=0;i--) {
            if (ans[nums[i]]) {
                return i/3+1;}
            ans[nums[i]] = true; }
        return 0;
    }
};