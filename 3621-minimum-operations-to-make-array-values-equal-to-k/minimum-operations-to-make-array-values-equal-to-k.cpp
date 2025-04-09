class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        unordered_set<int> res;
        for (int i:nums) {
            if(i<k) {
                return -1;
            } else if (i>k) {
                res.insert(i);
            }}
        return res.size();
    }
};
