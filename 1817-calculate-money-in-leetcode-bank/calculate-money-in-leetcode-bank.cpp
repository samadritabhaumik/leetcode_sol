class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int weeks=n/7;
        int rem=n%7;
        for(int i=0;i<weeks;++i) {
            sum+=7*(i+1)+21; 
        }
        for(int i=0;i<rem;++i) {
            sum +=weeks+1+i;
        }    
        return sum;
    }
};
