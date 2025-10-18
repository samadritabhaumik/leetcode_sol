class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0, prev = INT_MIN;
        for (int num : nums) {
            int lowerBound=num-k;
            int upperBound=num+k;
            if (prev < lowerBound) {
                prev = lowerBound;
                count++;
            } else if (prev < upperBound) {
                prev++;
                count++;
            }
        }
        return count;
    }
};