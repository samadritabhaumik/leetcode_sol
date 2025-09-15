class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
     int n=text.length();
        bool mp[26];
        for(char &ch:brokenLetters) {
            mp[ch-'a'] = true;
        }
        int result=0;
        bool found=false;
        for(char &ch:text) {
            if(ch == ' ') {
                if(!found) {
                result++;
                }
                found=false;
            } else if (mp[ch - 'a']) {
                found=true; 
            }
        }
        if(found==0)
            result++;
        return result;   
    }
};