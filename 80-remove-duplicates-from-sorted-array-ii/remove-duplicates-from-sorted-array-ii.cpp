class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=0;
        for(auto i:nums){
            if(n==0 || n==1 || nums[n-2]!=i){
                nums[n]=i;
                n+=1;
            }
        }
        return n;
    }
};