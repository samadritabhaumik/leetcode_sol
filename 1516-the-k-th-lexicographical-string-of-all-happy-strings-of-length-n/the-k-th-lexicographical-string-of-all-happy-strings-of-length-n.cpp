class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        generate(n,"",res);
        return res.size()<k ? "":res[k-1];
    }
    void generate(int n,string s,vector<string>& res){
        if(n==s.length()){ 
            res.push_back(s);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!s.empty() && s.back()==ch) continue;
            generate(n,s+ch,res);
        }}
};