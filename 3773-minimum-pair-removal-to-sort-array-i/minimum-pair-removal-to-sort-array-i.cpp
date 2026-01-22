class Solution {
public:
int solve(vector<int>& nums) {
        int mini=INT_MAX;
        int index=-1;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]+nums[i+1]<mini) {
                index=i;
                mini=nums[i]+nums[i+1];
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
       int ops=0;
        while(!is_sorted(begin(nums),end(nums))) {
            int ind=solve(nums);
            nums[ind]=nums[ind]+nums[ind+1];
            nums.erase(begin(nums)+ind+1);
            ops++;
        }
        return ops; 
    }
};