class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
      int n=nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++) {
            int shift = nums[i]%n; 
            int ind=(i + shift) % n;
            if(ind < 0) {
             ind += n;
            }
       result[i] = nums[ind];
        }
        return result;  
    }
};