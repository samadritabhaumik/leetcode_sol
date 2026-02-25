class Solution {
public:
int count(int num){
    int n=0;
    while(num){
        n+=num&1;
num>>=1;
    }
    return n;
}
    vector<int> sortByBits(vector<int>& arr) {
        auto i=[&](int &a,int &b){
            int c1=count(a);
            int c2=count(b);
            if(c1==c2) return a<b;
            return c1<c2;
        };
        sort(arr.begin(),arr.end(),i);
        return arr;
    }
};