class Solution {
    #define ll long long
    ll solve(vector<vector<int>>& ques,int pos,vector<ll>& mem){
        if(pos>=ques.size())
            return 0;
        if(mem[pos]!=-1)
            return mem[pos];
        ll exclude=solve(ques,pos+1,mem);
        ll include=ques[pos][0] + solve(ques,pos+ques[pos][1]+1,mem);
        return mem[pos] = max(exclude,include);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> mem(n,-1);
        return solve(questions,0,mem);
    }
};