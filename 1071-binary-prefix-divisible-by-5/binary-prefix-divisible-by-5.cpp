class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int count=0;
        for(int num:nums){
            count=(count*2+num)%5;
            result.push_back(count==0);
        }
        return result;
    }
};