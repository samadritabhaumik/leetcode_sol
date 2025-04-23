class Solution {
public:
    int solve(int num) {
        int sum=0;
        while(num) {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi=0;
        int count=0;
      for(int num = 1; num <= n; num++) {
            int digit = solve(num);
            mp[digit]++;
            if(mp[digit] == maxi) {
                count++;
            } else if(mp[digit] > maxi) {
                maxi=mp[digit];
                count=1;
            }}
        return count;
    }
};