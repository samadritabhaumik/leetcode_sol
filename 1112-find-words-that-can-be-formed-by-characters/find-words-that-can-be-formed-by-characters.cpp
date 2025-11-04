class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq1(26,0);
        for(char &ch:chars){
            freq1[ch-'a']++;
        }
        int res=0;
        for(string &w:words){
        vector<int> freq2(26,0);
        for(char &ch:w){
          freq2[ch-'a']++;
        }
        bool check=true;
        for(int i=0;i<26;i++)
        if(freq2[i]>freq1[i]){
            check=false;
        }
        if(check==true){
            res+=w.length();
        }}
        return res;
    }
};