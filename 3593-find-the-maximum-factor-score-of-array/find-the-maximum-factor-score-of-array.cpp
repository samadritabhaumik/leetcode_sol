class Solution {
public:
long long getGcd(long long a, long long b) {
        return b == 0 ? a : getGcd(b, a % b);
    }
    long long getLcm(long long a, long long b) {
        if (a == 0 || b == 0) return a + b;
        return (a / getGcd(a, b)) * b;
    }
    long long maxScore(vector<int>& nums) {
       int n=nums.size();
        if (n == 0) return 0;
        if (n == 1) return (long long)nums[0]*nums[0];
        vector<long long> preGcd(n), preLcm(n);
        preGcd[0] = nums[0];
        preLcm[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preGcd[i] = getGcd(preGcd[i - 1], nums[i]);
            preLcm[i] = getLcm(preLcm[i - 1], nums[i]);
        }
        vector<long long> sufGcd(n), sufLcm(n);
        sufGcd[n - 1] = nums[n - 1];
        sufLcm[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufGcd[i] = getGcd(sufGcd[i + 1], nums[i]);
            sufLcm[i] = getLcm(sufLcm[i + 1], nums[i]);
        }
        long long maxi = preGcd[n - 1] * preLcm[n - 1];
        for (int i = 0; i < n; ++i) {
            long long currentGcd, currentLcm;
            if (i == 0) {
                currentGcd = sufGcd[1];
                currentLcm = sufLcm[1];
            } else if (i == n - 1) {
                currentGcd = preGcd[n - 2];
                currentLcm = preLcm[n - 2];
            } else {
                currentGcd = getGcd(preGcd[i - 1], sufGcd[i + 1]);
                currentLcm = getLcm(preLcm[i - 1], sufLcm[i + 1]);
            }   
            maxi = max(maxi, currentGcd * currentLcm);
        }
        return maxi; 
    }
};