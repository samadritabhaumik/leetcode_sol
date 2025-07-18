class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> res;
        for(int i=0;i<n;i++){
            if(i==0 || groups[i]!=groups[i-1]){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};