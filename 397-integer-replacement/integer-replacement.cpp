class Solution {
public:
    int integerReplacement(int n) {
        long long N=n;
        int count=0;
        while (N>1) {
            if (N%2==0) {
                N/=2;
            } else {
                if (N==3||((N>>1)&1)==0) {
                N-=1;
                } else {
                N+=1;
                }}
            count++;}
            return count;
    }
};
