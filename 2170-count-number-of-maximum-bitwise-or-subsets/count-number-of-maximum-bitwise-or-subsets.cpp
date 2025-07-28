class Solution {
public:
 int count(int idx, int currOr, vector<int>& nums, int maxi) {
        if(idx==nums.size()) {
            if(currOr==maxi)
                return 1; 
            return 0;
        }
        int takeCount = count(idx+1,currOr|nums[idx],nums,maxi);
        int notTakeCount = count(idx+1,currOr,nums,maxi);
        return takeCount + notTakeCount;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int &num:nums) {
            maxi|=num;
        }
        int curr=0;
        return count(0,curr,nums,maxi);        
    }
};