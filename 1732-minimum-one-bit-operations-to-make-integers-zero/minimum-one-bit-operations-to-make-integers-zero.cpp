class Solution {
public:
    int minimumOneBitOperations(int n) {
        int m=n;
        while(m){
            m>>=1;
            n^=m;
        }
        return n;
    }
};