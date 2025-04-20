class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int res=0;
        for (int ans : answers) {
            mp[ans]++;
        }
        for (auto& [key, value]:mp) {
            int i=key+1;
            int groups=(value+i-1)/i;
            res+=groups*i;
        }
        return res;
    }
};