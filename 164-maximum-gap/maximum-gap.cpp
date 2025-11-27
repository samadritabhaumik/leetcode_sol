class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxi=INT_MIN,diff=0;
        sort(nums.begin(),nums.end());
        if(nums.size()<2) return 0;
        for(int i=0;i<nums.size()-1;i++){
        diff=nums[i+1]-nums[i];
        maxi=max(maxi,diff);
        }
        return maxi;
    }
};