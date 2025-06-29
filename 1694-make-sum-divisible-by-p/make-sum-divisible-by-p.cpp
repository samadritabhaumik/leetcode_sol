class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums)
            total=(total+num)%p;
        if (total==0) return 0;
        unordered_map<int, int> ind;
        ind[0] = -1;
        int res = n;
        long long prefix = 0;
        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - total + p) % p;

            if (ind.count(target)) {
                res = min(res, i - ind[target]);
            }
            ind[prefix] = i;}
        return res == n ? -1 : res;
    }
};
