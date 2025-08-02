class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> mp;
        for (int b1 : basket1) {
            mp[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2) {
            mp[b2]--;
            m = min(m, b2);
        }
        vector<int> res;
        for (auto [k, c]:mp) {
            if (c%2!=0) {
                return -1;
            }
            for (int i=0;i<abs(c)/2; ++i) {
                res.push_back(k);
            }
        }
        if (res.empty()) return 0;
        int half = res.size()/2;
        nth_element(res.begin(), res.begin() + half, res.end());
        long long count=0;
        for (int i = 0; i < half; ++i) {
            count+=min(2LL * m, static_cast<long long>(res[i]));
        }
        return count;
    }
};
