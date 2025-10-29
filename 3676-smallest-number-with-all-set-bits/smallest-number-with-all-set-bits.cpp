class Solution {
public:
int helper(int n){
    int count=0;
    while(n>0){
        count++;
        n=n/2;
    }
    return count;
}
    int smallestNumber(int n) {
        int nbits=helper(n);
        return (1<<nbits)-1;
    }
};