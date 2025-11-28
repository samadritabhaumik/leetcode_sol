class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ind=0;
        for(auto i:nums){
            if(i>nums[ind]){
                ind++;
            }
        }
        return ind;
    }
};