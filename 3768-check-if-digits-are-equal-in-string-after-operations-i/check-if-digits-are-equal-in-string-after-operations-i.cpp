class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
        if(n==0) return false;
        while(n>2){
            string res;
            for(auto i=0;i<n-1;i++){
                int sum=((s[i]-'0')+(s[i+1]-'0'))%10;
                res.push_back(sum + '0'); ;
            }
            s=res;
            n = s.length();
        }
        return s[0]==s[1];
    }
};