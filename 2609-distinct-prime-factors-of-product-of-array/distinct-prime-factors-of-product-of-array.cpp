class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        for(int num:nums){
            int n=num;
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    ans.insert(i);
                    while (n % i == 0) {
                    n/=i;
                }
                }
            }
            if(n>1) ans.insert(n);
        }
        return ans.size();
    }
};