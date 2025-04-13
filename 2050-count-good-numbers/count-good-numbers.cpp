class Solution {
public:
const int M=1e9+7;
int solve(long long a,long long b){
    if(b==0) return 1;
    long long half=solve(a,b/2);
    long long ans=(half*half)%M;
    if(b%2==1){
        ans=(ans*a)%M;
    }
    return ans;
}
    int countGoodNumbers(long long n) {
        return (long long)solve(5,(n+1)/2)*solve(4,n/2)%M;
    }
};