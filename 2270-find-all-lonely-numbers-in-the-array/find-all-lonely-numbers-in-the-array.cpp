class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i:nums){
            mp[i]++;
        }
        for(auto& [num,count] :mp) {
    if(count == 1 && mp.find(num - 1)==mp.end() && mp.find(num + 1)==mp.end()) {
                res.push_back(num);
            }}
            return res;
    }
};