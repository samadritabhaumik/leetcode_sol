class Solution {
public:
    bool solve(int x) {
        vector<int> count(10);
        while (x > 0) {
            int n=x%10;
            count[n]++;
            x/=10;
        }
        for (int d=0;d<10;++d) {
            if (count[d] > 0 && count[d] !=d) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i=n+1;i<=1300000;++i) {
            if (solve(i)) {
                return i;
            }
        }
        return -1;
    }
};