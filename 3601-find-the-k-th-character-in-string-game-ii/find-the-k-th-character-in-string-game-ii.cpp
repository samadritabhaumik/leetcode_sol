class Solution {
public:
    #define ll long long
    char kthCharacter(long long k, vector<int>& operations) {
        int count=0;
        ll val=k;
        while(val>1){
            int jumps=ceil(log2(val));
            val-=pow(2,jumps-1);
            count+=operations[jumps-1];
        }
        return char('a'+(count%26));
    }
};