class Solution {
public:
    bool checkOnesSegment(string s) {
        bool check=false;
        for(int i=0;i<s.length();i++){
           if (s[i]=='0') {
                check=true; 
            }
            if (check && s[i]=='1') {
                return false;
            }
        }
        return true;
    }
};