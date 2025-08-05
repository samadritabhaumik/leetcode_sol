class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back({nums2[i], i});
        }
        sort(nums.begin(), nums.end());
        vector<int> res(n);
        int low = 0, high = n - 1;
        for (int i = 0; i < n; ++i) {
            int val = nums1[i];
            if (val > nums[low].first) {
                res[nums[low].second] = val;
                ++low;
            } else {
                res[nums[high].second] = val;
                --high;
            }
        }
        return res;
    }
};
