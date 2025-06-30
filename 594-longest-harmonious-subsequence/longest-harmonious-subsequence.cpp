class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num:nums) {
            freq[num]++;
        }
        int maxi=0;
        for (auto& [key,val]:freq) {
            if (freq.count(key + 1)) {
                maxi=max(maxi,val+freq[key+1]);
            }}
        return maxi;
    }
};
