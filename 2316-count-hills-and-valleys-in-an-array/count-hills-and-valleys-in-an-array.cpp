class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                res.push_back(nums[i]);
            }}
        for (int i = 1; i < res.size() - 1; ++i) {
            if ((res[i] > res[i - 1] && res[i] > res[i + 1]) ||
                (res[i] < res[i - 1] && res[i] < res[i + 1])) {
                count++;
            }}
        return count;
    }
};
