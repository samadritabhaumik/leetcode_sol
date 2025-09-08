class Solution {
public:
bool nozero(int n){
    while(n!=0){
        int d=n%10;
        if(d==0)
        return false;
        n=n/10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        int a=1;
        int b=n-1;
        while(true){
            if(nozero(a) && nozero(b))
            break;
            a++;
            b--;
     
        }
        return {a,b};
    }
};