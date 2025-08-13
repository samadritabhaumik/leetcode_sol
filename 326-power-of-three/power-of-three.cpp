class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;i<=30;i++){
long long d=pow(3,i);
    if(d==n)
        return true;
        }
        return false;
    }
};