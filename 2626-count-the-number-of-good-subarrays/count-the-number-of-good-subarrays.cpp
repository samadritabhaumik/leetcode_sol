class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        long long res=0,count=0;
        while(j<n){
            count+=mp[nums[j]];
            mp[nums[j]]++;
            while(count>=k){
                res+=(n-j);
                mp[nums[i]]--;
                count-=mp[nums[i]];
                i++;
            }
            j++;
        }
return res;
    }
};