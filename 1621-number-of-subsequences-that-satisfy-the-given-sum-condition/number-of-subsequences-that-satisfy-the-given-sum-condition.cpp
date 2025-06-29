class Solution {
    int MOD = 1e9+7;
    void solve(vector<int>& power_of_two,int& n){
        power_of_two[0]=1;
        for(int i=1;i<n;++i)
            power_of_two[i] = (power_of_two[i-1]*2LL)%MOD;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(n);
        solve(res,n);
      sort(nums.begin(),nums.end());
        int count=0;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]+nums[right]>target)
                right--;
            else{
                count = (count + res[right-left])%MOD;
                left++;
            }
        }
        return count;
    }
};