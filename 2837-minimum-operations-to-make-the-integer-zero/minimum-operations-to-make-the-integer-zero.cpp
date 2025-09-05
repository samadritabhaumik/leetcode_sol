class Solution {
public:
    int solve(long long n) {
        int cnt = 0;
        while (n > 0) {
            if (n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            long long x = num1 - 1LL * num2 * k; 
            if (x < k) {
                return -1;
            }
            if (k >= solve(x)) {
                return k;
            }
            k++;
        }
    }
};
