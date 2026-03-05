class Solution {
public:
    int minOperations(string s) {
       int s1=0;
        int s2=0; 
        for(int i=0;i<s.length();i++) {
            if((i%2==0 && s[i]!='0') || (i%2==1 && s[i]!='1'))
                s1++;
            if((i%2==0 && s[i]!='1') || (i%2==1 && s[i]!='0'))
                s2++;
        }
        return min(s1,s2); 
    }
};