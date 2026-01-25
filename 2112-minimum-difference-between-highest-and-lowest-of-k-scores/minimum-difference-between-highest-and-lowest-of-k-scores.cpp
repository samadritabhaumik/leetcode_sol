class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mini = INT_MAX;
        int i = 0;
        int j = i+k-1;
        while(j < n) {
            int minele=nums[i];
            int maxele=nums[j];
            mini=min(mini,maxele-minele);
            i++;
            j++;
        }
        return mini;
    }
};