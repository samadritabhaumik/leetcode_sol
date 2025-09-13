class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        unordered_set<char> st={'a','e','i','o','u'};
        int mv=0,mc=0;
        for(char ch:s){
            int idx=ch-'a';
            freq[idx]++;
            if(st.count(ch)){
            mv=max(mv,freq[idx]);
            } 
            else{
            mc=max(mc,freq[idx]);
            }}
        return mv+mc;  
    }
};